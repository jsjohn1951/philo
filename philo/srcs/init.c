/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:42:13 by wismith           #+#    #+#             */
/*   Updated: 2022/05/20 20:10:00 by wismith          ###   ########.fr       */
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
	id = preset->current_spawn;
	if (!(preset->current_spawn % 2))
		printf(KGRN);
	else
		printf(KRED);
	init_tphilo(preset, id);
	print_action(preset->tv, preset, id, "has spawned");
	printf(KNRM);
	return (NULL);
}

/* giving birth to pThreads... */
/* Not as easy as it looks! */

void	birth_machine(t_times *preset)
{
	int	i;

	i = 1;
	while (i <= preset->n_philo && preset->n_philo > 0)
	{
		preset->current_spawn = i;
		pthread_create(&preset->philo[i - 1].thread_id, NULL, spawner, preset);
		pthread_join(preset->philo[i - 1].thread_id, NULL);
		i++;
	}
}
