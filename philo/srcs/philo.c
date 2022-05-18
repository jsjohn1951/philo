/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:57:01 by wismith           #+#    #+#             */
/*   Updated: 2022/05/17 17:05:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_times	preset;

	if (argc != 5 && argc != 6)
		msg1();
	parser(&preset, argc, argv);
	printf(KBLU"\n\t😎Hello World!\n"KNRM);
	printf("Number of 'philos' requested: '%s%d%s'\n", KMAG, preset.n_philo, KNRM);
	printf(KGRN"\t🥵Initializing...\n\n"KNRM);
	usleep(2000000);
	printf(KCLR);
	return (0);
}
