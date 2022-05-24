/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:34:10 by wismith           #+#    #+#             */
/*   Updated: 2022/05/24 14:36:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

void	msg4(void)
{
	ft_putstr("Error\n", 2);
	ft_putstr("\tNegative numbers found!\n", 2);
	exit(1);
}

void	msg3(void)
{
	ft_putstr("Error\n", 2);
	ft_putstr("\tValues greater than INT_MAX!\n", 2);
	exit(1);
}

void	msg2(void)
{
	ft_putstr("Error\n", 2);
	ft_putstr("\tNonnumeric value detected!\n", 2);
	exit(1);
}

void	msg1(void)
{
	ft_putstr("Error\n", 2);
	ft_putstr("\tIncorrect num arguments!\n", 2);
	exit(1);
}
