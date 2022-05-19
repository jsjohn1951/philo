/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:35 by wismith           #+#    #+#             */
/*   Updated: 2022/05/19 17:13:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(struct timeval *tv, t_times *preset, int id, char *s)
{
	printf("%lld %d %s\n", timestamp(tv) - preset->init_time, id, s);
}
