/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:42:13 by wismith           #+#    #+#             */
/*   Updated: 2022/05/25 18:13:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	smart_chill(unsigned long i, t_times *preset)
{
	unsigned long	current;

	current = philo_timestamp(preset);
	while ((philo_timestamp(preset) - current) < i)
		;
}

void	print_action(t_times *preset, int id, char *s)
{
	unsigned long	new_timestamp;

	new_timestamp = philo_timestamp(preset);
	pthread_mutex_lock(preset->mutex);
	printf("%lld %d %s\n", new_timestamp - preset->init_time, id, s);
	pthread_mutex_unlock(preset->mutex);
}

void	init_tphilo(t_times *preset, int id)
{
	preset->philo[id - 1].fork_l = 1;
	preset->philo[id - 1].fork_r = 0;
	preset->philo[id - 1].eating = 0;
	preset->philo[id - 1].sleeping = 0;
	preset->philo[id - 1].dead = 0;
}

void	*spawner(void *pre)
{
	t_times			*preset;
	int				id;
	// int				i;

	// i = 0;
	preset = (t_times *) pre;
	pthread_mutex_lock(preset->mutex);
	id = preset->current_spawn;
	pthread_mutex_unlock(preset->mutex);
	print_action(preset, id, "has spawned");
	// smart_chill(1, preset);
	// init_tphilo(preset, id);
	// while (!death_check(preset) && i < 2)
	// {
	// 	usleep(200);
	// 	pthread_mutex_lock(preset->mutex);
	// 	print_action(preset->tv, preset, id, "is alive");
	// 	pthread_mutex_unlock(preset->mutex);
	// 	if (death_check(preset))
	// 		return (NULL);
	// 	i++;
	// }
	return (NULL);
}

/* giving birth to pThreads... */
/* Not as easy as it looks! */

void	birth_machine(t_times *preset)
{
	int				i;
	pthread_mutex_t	mutex;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	preset->mutex = &mutex;
	while (++i <= preset->n_philo && preset->n_philo > 0)
	{
		preset->current_spawn = i;
		if (pthread_create(&preset->philo[i - 1].thread_id, NULL,
				spawner, preset))
			exit(1);
		smart_chill(1, preset);
	}
	i = 0;
	while (++i <= preset->n_philo && preset->n_philo > 0)
	{
		if (pthread_join(preset->philo[i - 1].thread_id, NULL))
			exit(1);
	}
}
