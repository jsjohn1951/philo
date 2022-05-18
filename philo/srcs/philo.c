/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:57:01 by wismith           #+#    #+#             */
/*   Updated: 2022/05/18 21:51:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_times			preset;
	struct timeval	tv;

	if (argc != 5 && argc != 6)
		msg1();
	parser(&preset, argc, argv);
	printf(KBLU"\n\t😎Hello World!\n"KNRM);
	printf("Number of 'philos' requested: '%s%d%s'\n", KMAG,
		preset.n_philo, KNRM);
	printf(KGRN"\t🥵Initializing...\n\n"KNRM);
	usleep(2000000);
	printf(KCLR);
	preset.init_time = timestamp(&tv);
	print_action(&tv, &preset, 1, "has taken a fork");
	usleep(500);
	print_action(&tv, &preset, 2, "is sleeping");
	usleep(500);
	print_action(&tv, &preset, 3, "is thinking");
	return (0);
}
