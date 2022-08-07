/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:14:08 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 15:31:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*process_(void *dat)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *) dat;
	data = (t_data *) philo->data;
	i = 0;
	if (!(philo->id % 2))
		alarm_clock(4, data);
	while (i < 4 && !data->deaths)
	{
		if (philo->local.must_eat)
			if (!philo->local.me_)
				return (NULL);
		usleep(150);
		life_(data, philo, &i);
		i++;
	}
	return (NULL);
}

void	init_philo_(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo[i].alive = 1;
	data->philo[i].data = (void *) data;
	data->philo[i].l_fork = 0;
	data->philo[i].r_fork = 0;
	if (i == 0)
		data->philo[i].l_id = data->np_ - 1;
	else
		data->philo[i].l_id = data->philo[i].id - 2;
	data->philo[i].r_id = data->philo[i].id - 1;
	data->philo[i].last_time_eat = new_stamp(data);
	data->forks[i] = 0;
	data->philo[i].times_eatin = 0;
	local_vars_(data, &data->philo[i]);
}

void	init_mutex_(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->np_)
		pthread_mutex_init(&data->fork_m[i], NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->eat, NULL);
}

void	destroy_mutex_(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->np_)
		pthread_mutex_destroy(&data->fork_m[i]);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->eat);
}

void	init_(t_data *data)
{
	int		i;

	i = -1;
	data->deaths = 0;
	init_mutex_(data);
	init_time_(data);
	while (++i < data->np_)
		init_philo_(data, i);
	i = 0;
	while (i < data->np_)
	{
		pthread_create(&data->philo[i].thread_id,
			NULL, process_, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->np_)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
	destroy_mutex_(data);
}
