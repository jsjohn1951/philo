/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:42:13 by wismith           #+#    #+#             */
/*   Updated: 2022/05/19 17:48:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*spawner(void *pre)
{
	t_times			*preset;

	preset = (t_times *) pre;
	print_action(preset->tv, preset, preset->current_spawn, "has spawned");
	return (NULL);
}

void	birth_machine(t_times *preset)
{
	int	i;

	i = 1;
	while (i <= preset->n_philo && preset->n_philo > 0)
	{
		preset->philo[i - 1].id = i;
		preset->current_spawn = i;
		pthread_create(&preset->philo[i - 1].thread_id, NULL, spawner, preset);
		pthread_join(preset->philo[i - 1].thread_id, NULL);
		i++;
	}
}
