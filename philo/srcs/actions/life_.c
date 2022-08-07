/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:15:52 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 13:42:32 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	life_(t_data *data, t_philo *philo, int *i)
{
	if (new_stamp(data) - philo->last_time_eat
		>= (unsigned long) philo->local.td_)
	{
		print_(philo, "died");
		pthread_mutex_lock(&data->death);
		data->deaths = 1;
		pthread_mutex_unlock(&data->death);
	}
	pthread_mutex_lock(&data->death);
	if (!data->deaths)
	{
		pthread_mutex_unlock(&data->death);
		if (*i == 1)
			try_eat_(philo, data);
		if (*i == 2)
			alarm_clock(print_(philo, "is sleeping"), data);
		if (*i == 3)
			*i = print_(philo, "is thinking");
	}
	else
	{
		pthread_mutex_unlock(&data->death);
		*i = 4;
	}
}
