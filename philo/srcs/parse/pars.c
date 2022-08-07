/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:53:10 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 15:16:45 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

char	*check_(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && i == 0)
			i++;
		if (s[i] < '0' || s[i] > '9')
		{
			write(2, "contains nonnumericals\n",
				ft_strlen("contains nonnumericals\n"));
			exit(1);
		}
		i++;
	}
	return (s);
}

void	parser_(t_data *data, char **argv)
{
	t_err	err;

	err.err = 0;
	data->deaths = 0;
	data->np_ = num_cmp(ft_atoi(check_(argv[1]), &err), 200, &err);
	data->td_ = ft_atoi(check_(argv[2]), &err);
	data->te_ = ft_atoi(check_(argv[3]), &err);
	data->ts_ = ft_atoi(check_(argv[4]), &err);
	if (data->argc == 5)
	{
		data->me_ = ft_atoi(check_(argv[5]), &err);
		data->must_eat = 1;
	}	
	if (err.err == 1)
		ft_put_(2, "Argument exceeding INT_MAX detected!\n");
	if (err.err == 2)
		ft_put_(2, "Number of philos exceeds: 200\n");
	if (err.err == -1)
		ft_put_(2, "Found a Negative argument\n");
	if (err.err)
		exit (1);
}
