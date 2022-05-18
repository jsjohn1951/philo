/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:57:47 by wismith           #+#    #+#             */
/*   Updated: 2022/05/17 22:43:35 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define KCLR  "\e[1;1H\e[2J"

typedef struct s_times
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	num_philo_eats;
}	t_times;

/* Error msgs */
void	msg1(void);
void	msg2(void);
void	msg3(void);
void	msg4(void);

/* tools */
void	parser(t_times *preset, int argc, char **argv);
int		ft_atoi(const char *nptr);
int		ft_putstr(char *s, int fd);
int		ft_strlen(char *s);

#endif