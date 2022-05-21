/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:57:01 by wismith           #+#    #+#             */
/*   Updated: 2022/05/20 20:04:13 by wismith          ###   ########.fr       */
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
	preset.tv = &tv;
	birth_machine(&preset);
	return (0);
}
