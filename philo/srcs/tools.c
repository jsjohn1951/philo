/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:52:25 by wismith           #+#    #+#             */
/*   Updated: 2022/05/17 22:43:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

int	ft_atoi(const char *nptr)
{
	size_t	res;
	int		i;

	res = 0;
	i = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
		res = (res * 10) + (nptr[i++] - '0');
	if (res > INT_MAX)
		msg3();
	return (res);
}

int	num_check(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '-')
		msg4();
	while (s[++i])
		if (s[i] < '0' || s[i] > '9')
			msg2();
	return (ft_atoi(s));
}

void	parser(t_times *preset, int argc, char **argv)
{
	preset->n_philo = num_check(argv[1]);
	preset->t_die = num_check(argv[2]);
	preset->t_eat = num_check(argv[3]);
	preset->t_sleep = num_check(argv[4]);
	if (argc == 6)
		preset->num_philo_eats = num_check(argv[5]);
	else
		preset->num_philo_eats = -1;
	if (preset->n_philo == 0 || preset->n_philo > 250 || preset->num_philo_eats == 0)
		exit(1);
}
