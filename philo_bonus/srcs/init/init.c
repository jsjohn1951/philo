/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:14:08 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 12:19:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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

void	init_(t_data *data)
{
	(void) data;
}
