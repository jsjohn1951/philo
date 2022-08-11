/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:57:57 by wismith           #+#    #+#             */
/*   Updated: 2022/08/07 15:16:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_(int argc, char **argv)
{
	t_data	data;

	data.argc = argc - 1;
	data.must_eat = 0;
	data.me_ = 0;
	parser_(&data, argv);
	init_(&data);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		printf("-> incorrect num args\n");
	else
		philo_(argc, argv);
	return (0);
}
