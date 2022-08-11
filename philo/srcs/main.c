/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:57:57 by wismith           #+#    #+#             */
/*   Updated: 2022/08/11 17:22:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_(int argc, char **argv)
{
	t_err	err;
	t_data	data;

	data.argc = argc - 1;
	data.must_eat = 0;
	data.me_ = 0;
	parser_(&data, argv, &err);
	if (err.err)
		return (1);
	init_(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		printf("-> incorrect num args\n");
	else
		return (philo_(argc, argv));
	return (1);
}
