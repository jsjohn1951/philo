/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:35 by wismith           #+#    #+#             */
/*   Updated: 2022/05/21 16:31:58 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(struct timeval *tv, t_times *preset, int id, char *s)
{
	printf("%lld %d %s\n", timestamp(tv) - preset->init_time, id, s);
}

void	feaster(t_times *preset, int id)
{
	int	current_time;

	current_time = timestamp(preset->tv);
	if (preset->num_forks >= 2)
	{
		print_action(preset->tv, preset, id, "is eating");
		preset->num_forks -= 2;
		preset->philo[id - 1].forks += 2;
		while (timestamp(preset->tv) - current_time < preset->t_eat)
			;
		preset->num_forks += 2;
		preset->philo[id - 1].forks -= 2;
	}
}
