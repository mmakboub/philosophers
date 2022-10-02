/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:21:55 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/03 00:47:31 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#include <sys/time.h>

typedef struct s_compstargs{
    int die;
    int eat;
    int sleep;
    int nbr_philo;
    int x_time_musteat;
    int start;
	
}t_compstargs;

typedef struct s_philo_info{
    
    pthread_t   *philo;
    pthread_mutex_t *fork;
    pthread_mutex_t *next_fork;
    t_compstargs	*args;
    int index;
    bool status;
    int get_time;
}t_philo_info;


void    check_argument( char **argv, int ac);
int     check_digit(char **argument);
void    initialiaze_argv(t_compstargs   *argphilo, char **av, int ac);
int	    errorinargument();
int     ft_atoi(const char *str);
int	    ft_isdigit(int x);
#endif