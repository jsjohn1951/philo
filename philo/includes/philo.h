/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:12:09 by wismith           #+#    #+#             */
/*   Updated: 2022/08/13 17:45:51 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_local
{
	int				td_;
	int				te_;
	int				ts_;
	int				np_;
	int				me_;
	int				r_;
	int				l_;
	int				rtn;
	unsigned long	new_time;
	unsigned long	res;
	int				i;
	int				must_eat;
}	t_local;

typedef struct s_philo
{
	void			*data;
	pthread_t		thread_id;
	int				id;
	int				l_id;
	int				r_id;
	int				last_time_eat;
	int				alive;
	int				eatin;
	int				times_eatin;
	unsigned long	current_time;
	unsigned long	init_time;
	struct timeval	tv;
	t_local			local;
}	t_philo;

typedef struct s_data
{
	int				np_;
	int				td_;
	int				te_;
	int				ts_;
	int				must_eat;
	int				me_;
	pthread_mutex_t	fork_m[200];
	pthread_mutex_t	death;
	int				deaths;
	int				argc;
	int				forks[200];
	t_philo			philo[200];
}	t_data;

typedef struct s_err
{
	int	err;
}	t_err;

/*	parse */
/* file: pars */
void			parser_(t_data *data, char **argv, t_err *err);
char			*check_(char *s);

/*	init */
/* file: init */
void			init_(t_data *data);
void			*process_(void *dat);
void			local_vars_(t_data *data, t_philo *p);

/*	tools */
/* file: basic */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strlen(char *s);
int				num_cmp(int num, int cmp, t_err *err);
void			ft_put_(int fd, char *s);
/* file: print */
int				print_(t_philo *philo, char *s);
/* file: time */
void			init_time_(t_philo *p);
void			alarm_clock(unsigned long time, t_data *data, t_philo *p);
unsigned long	new_stamp(t_philo *p);
unsigned long	new_stamp_lonely(t_philo *p);

/*	actions */
/* file: eat_ */
void			try_eat_(t_philo *p, t_data *data);
/* file: life_ */
void			life_(t_data *data, t_philo *p, int *i);
int				death_(t_data *data, t_philo *p);
/* file: lonely_life */
void			ft_lonely_death(t_data *data, t_philo *p);

#endif