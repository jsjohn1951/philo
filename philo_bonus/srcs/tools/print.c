/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:35:07 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 12:20:15 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_(t_philo *philo, char *s)
{
	t_data	*data;

	data = (t_data *) philo->data;
	printf("%lums %d %s\n", new_stamp(data, philo), philo->id, s);
	if (!ft_strncmp(s, "is sleeping", ft_strlen("is sleeping") - 1))
		return (philo->local.ts_);
	if (!ft_strncmp(s, "is eating", ft_strlen("is eating") - 1))
		return (philo->local.te_);
	return (0);
}
