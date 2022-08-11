/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:39:18 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 17:12:19 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	lonely_death_(t_data *data, t_philo *p)
{
	p->current_time = new_stamp_lonely(p);
	if (p->current_time - p->last_time_eat
		>= (unsigned long) p->local.td_)
	{
		printf("%lu 1 died\n", p->current_time);
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
				printf("%lu 1 has taken a fork\n",
					p->current_time);
			if (i == 2)
			{
				printf("%lu 1 is sleeping\n", p->current_time);
				alarm_clock(p->local.ts_, data, p);
			}
			if (i == 3)
			{
				printf("%lu 1 is thinking\n", p->current_time);
				i = 0;
			}
			i++;
		}
	}
}
