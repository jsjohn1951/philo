/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:39:18 by wismith           #+#    #+#             */
/*   Updated: 2022/08/10 15:57:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	lonely_death_(t_data *data, t_philo *p)
{
	p->current_time = new_stamp(data, p);
	if (p->current_time - p->last_time_eat
		>= (unsigned long) p->local.td_)
	{
		print_(p, "died");
		data->deaths = 1;
		return (1);
	}
	return (0);
}

void	ft_lonely_death(t_data *data, t_philo *p)
{
	int	i;

	i = 1;
	if (p->local.np_ == 1)
	{
		while (!data->deaths)
		{
			if (lonely_death_(data, p))
				i = 4;
			if (i == 1)
				print_(p, "grabbed a fork");
			if (i == 2)
			{
				print_(p, "is sleeping");
				usleep(p->local.ts_ * 1000);
			}
			if (i == 3)
			{
				print_(p, "is thinking");
				i = 0;
			}
			i++;
		}
	}
}
