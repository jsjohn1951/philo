/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:42:13 by wismith           #+#    #+#             */
/*   Updated: 2022/05/23 14:26:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_tphilo(t_times *preset, int id)
{
	preset->philo[id - 1].forks = 0;
	preset->philo[id - 1].eating = 0;
	preset->philo[id - 1].sleeping = 0;
	preset->philo[id - 1].dead = 0;
}

void	*spawner(void *pre)
{
	t_times			*preset;
	int				id;

	preset = (t_times *) pre;
	pthread_mutex_lock(preset->mutex);
	id = preset->current_spawn;
	print_action(preset->tv, preset, id, "has spawned");
	pthread_mutex_unlock(preset->mutex);
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
		usleep(2);
	}
	i = 0;
	while (++i <= preset->n_philo && preset->n_philo > 0)
	{
		if (pthread_join(preset->philo[i - 1].thread_id, NULL))
			exit(1);
	}
}
