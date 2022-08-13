/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:14:08 by wismith           #+#    #+#             */
/*   Updated: 2022/08/13 17:45:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*process_(void *dat)
{
	t_philo	*p;
	t_data	*data;

	p = (t_philo *) dat;
	data = (t_data *) p->data;
	p->local.i = 1;
	p->last_time_eat = new_stamp(p);
	ft_lonely_death(data, p);
	while (p->local.i < 4)
	{
		if (p->local.must_eat)
			if (!p->local.me_)
				return (NULL);
		life_(data, p, &p->local.i);
		p->local.i++;
		usleep(150);
	}
	return (NULL);
}

void	init_philo_(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo[i].alive = 1;
	data->philo[i].data = (void *) data;
	if (i == 0)
		data->philo[i].l_id = data->np_ - 1;
	else
		data->philo[i].l_id = data->philo[i].id - 2;
	data->philo[i].r_id = data->philo[i].id - 1;
	data->forks[i] = 0;
	data->philo[i].times_eatin = 0;
	data->philo[i].eatin = 0;
	local_vars_(data, &data->philo[i]);
}

void	init_mutex_(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->np_)
		pthread_mutex_init(&data->fork_m[i], NULL);
	pthread_mutex_init(&data->death, NULL);
}

void	destroy_mutex_(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->np_)
		pthread_mutex_destroy(&data->fork_m[i]);
	pthread_mutex_destroy(&data->death);
}

void	init_(t_data *data)
{
	int		i;

	i = -1;
	data->deaths = 0;
	init_mutex_(data);
	while (++i < data->np_)
		init_philo_(data, i);
	i = -1;
	while (++i < data->np_)
	{
		init_time_(&data->philo[i]);
		pthread_create(&data->philo[i].thread_id,
			NULL, process_, &data->philo[i]);
	}
	i = -1;
	while (++i < data->np_)
		pthread_join(data->philo[i].thread_id, NULL);
	destroy_mutex_(data);
}
