/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:36:32 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/10 14:20:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int init_mutex(t_philo_info *philo)
{
    int i = 1;
    
    philo[0].args->for_writing = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(philo->args->for_writing, NULL);
    while(i < philo->args->nbr_philo)
    {
       philo[i].args->for_writing =  philo[0].args->for_writing;
        i++;
    }
    return(1);
}
int    initialiaze_all(t_compstargs   *argphilo, t_philo_info    *philo, char **av)
{
    int i;
    i = 0;
    argphilo->nbr_philo = ft_atoi(av[1]);
    argphilo->die = ft_atoi(av[2]);
    argphilo->eat = ft_atoi(av[3]);
    argphilo->sleep = ft_atoi(av[4]);
    argphilo->x_time_musteat = 0;
    argphilo->timehascome = 1;
    if(argphilo->nbr_philo == 0)
        return(write(1, "invalide argument\n", 17), 0);
    if(av[5])
            argphilo->x_time_musteat = ft_atoi(av[5]);
    while(i < argphilo->nbr_philo)
    {
        philo[i].index = i + 1;
        philo[i].args = argphilo;
        philo[i].last_meal = getting_time();
        argphilo->nbrofeats = 0;
        i++;
    }
    init_mutex(philo);
    return(1);
}


int init_next_fork(t_philo_info *philo)
{
    int i = 0;
    
    while(i < philo->args->nbr_philo)
    {
        philo[i].next_fork = philo[(i + 1) % philo->args->nbr_philo].fork;
        i++;
    }
    return(1);
}
int init_fork(t_philo_info *philo)
{
    int i = 0;
    while(i < philo->args->nbr_philo)
    {
        philo[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if (!philo[i].fork)
            return(0);
        pthread_mutex_init(philo[i].fork, NULL);
        i++;
    }
    return(1);
}