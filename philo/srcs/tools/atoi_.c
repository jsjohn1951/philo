/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:25:46 by wismith           #+#    #+#             */
/*   Updated: 2022/08/02 13:39:05 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	atoi_check_(size_t res, int ncounter, t_err *err)
{
	if (res > 2147483647 && ncounter == 1)
		err->err = 1;
	else if (ncounter == -1)
		err->err = -1;
}

int	ft_atoi(const char *nptr, t_err *err)
{
	size_t	res;
	int		i;
	int		ncounter;

	res = 0;
	i = 0;
	ncounter = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i++] == '-')
		ncounter = -1;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		res = (res * 10) + (nptr[i++] - 48);
		atoi_check_(res, ncounter, err);
		if (err->err)
			return (1);
	}
	return ((int)(res * ncounter));
}
