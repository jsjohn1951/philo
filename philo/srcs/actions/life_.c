/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:15:52 by wismith           #+#    #+#             */
/*   Updated: 2022/08/08 00:26:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	death_(t_data *data, t_philo *p)
{
	p->current_time = new_stamp(data);
	if (p->current_time - p->last_time_eat
		>= (unsigned long) p->local.td_ + 9)
	{
		print_(p, "died");
		pthread_mutex_lock(&data->death);
		data->deaths = 1;
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	return (0);
}

void	life_(t_data *data, t_philo *philo, int *i)
{
	if (death_(data, philo) || data->deaths)
	{
		*i = 4;
		return ;
	}
	if (*i == 1)
		try_eat_(philo, data);
	if (*i == 2)
		alarm_clock(print_(philo, "is sleeping"), data);
	if (*i == 3)
		*i = print_(philo, "is thinking");
}
