/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:21:55 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/18 22:47:38 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct s_compstargs{
    int die;
    int eat;
    int sleep;
    int nbr_philo;
    int nb_time_philo_musteat;
    pthread_t   *philo;
	
}t_compstargs;
void    check_argument( char **argv, int ac);
int    check_digit(char **argument);
void    initialiaze_argv(t_compstargs   *argphilo, char **av, int ac);
int	    errorinargument();
int     ft_atoi(char *str);
int	    ft_isdigit(int x);
#endif