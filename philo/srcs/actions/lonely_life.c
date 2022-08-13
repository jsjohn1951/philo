/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:39:18 by wismith           #+#    #+#             */
/*   Updated: 2022/08/13 17:45:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

// int	lonely_death_(t_data *data, t_philo *p)
// {
// 	p->current_time = new_stamp_lonely(p);
// 	if (p->current_time - p->last_time_eat
// 		>= (unsigned long) p->local.td_)
// 	{
// 		printf("%lu 1 died\n", p->current_time);
// 		data->deaths = 1;
// 		return (1);
// 	}
// 	return (0);
// }

void	ft_lonely_death(t_data *data, t_philo *p)
{
	if (p->local.np_ == 1)
		alarm_clock(p->local.td_, data, p);
}
