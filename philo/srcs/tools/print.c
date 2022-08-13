/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:35:07 by wismith           #+#    #+#             */
/*   Updated: 2022/08/13 15:08:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_(t_philo *philo, char *s)
{
	t_data	*data;

	data = (t_data *) philo->data;
	pthread_mutex_lock(&data->death);
	printf("%lums %d %s\n", philo->current_time, philo->id, s);
	pthread_mutex_unlock(&data->death);
	if (!ft_strncmp(s, "is sleeping", ft_strlen("is sleeping") - 1))
		return (philo->local.ts_);
	if (!ft_strncmp(s, "is eating", ft_strlen("is eating") - 1))
		return (philo->local.te_);
	return (0);
}
