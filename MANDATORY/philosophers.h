/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:21:55 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/12 13:44:53 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_compstargs{
	int				die;
	int				eat;
	int				sleep;
	int				nbr_philo;
	int				x_time_musteat;
	pthread_mutex_t	*for_writing;
	int				nbrofeats;
	int				timehascome;
	int				done;
}t_compstargs;

typedef struct s_philo_info{
	pthread_t		philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	t_compstargs	*args;
	int				index;
	int				get_time;
	long			start;
	long			last_meal;
}t_philo_info;

int		check_digit(char **argument);
int		initialiaze_all(t_compstargs *argphilo, t_philo_info *philo, char **av);
int		errorinargument(void);
double	ft_atoi(const char *str);
int		ft_isdigit(int x);
long	get_time(void);
void	*routine(void *argv);
int		creatthreads(t_compstargs *argphilo, t_philo_info *philos);
int		init_next_fork(t_philo_info *philo);
int		init_fork(t_philo_info *philo);
int		init_mutex(t_philo_info *philo);
void	is_sleeping(t_philo_info *philo);
void	is_thinking(t_philo_info *philo);
void	taking_fork(t_philo_info *philo);
void	taking_next_fork(t_philo_info *philo);
int		x_time_musteat(t_philo_info *philo);
int		is_eating(t_philo_info *philo);
void	get_break(long sleep_time);
long	getting_time(void);
void	checking_death(t_philo_info *philo);
long	execution_time(t_philo_info *philo);
int		ititialiaze2(t_compstargs *argphilo, char **av);
void	destroy_all(t_philo_info *philo, t_compstargs *arg);
#endif
