/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fonctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:57:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/06 00:39:36 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

// time imta creater thread
// time for last time philo start eating
void get_break(long sleep_time)
{
    long wake_up;
    wake_up = getting_time() + sleep_time;
    while(getting_time() < wake_up)
    {
        usleep(40);
    }
}

void is_sleeping(t_philo_info *philo)
{
    pthread_mutex_lock(philo[i].for_writing)
    printf("%ld philosophe %ld is sleeping\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo[i].for_writing)
    usleep(100);
}

void is_thinking(t_philo_info *philo)
{
    pthread_mutex_lock(philo[i].for_writing)
    printf("%ld philosophe %ld is thinking\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo[i].for_writing)
}

void taking_fork(t_philo_info *philo)
{
    if(!(pthread_mutex_lock(fork)) || !(pthread_mutex_lock(philo[i].for_writing)))
        return(0);
    pthread_mutex_lock(fork);
    pthread_mutex_lock(philo[i].for_writing)
    printf("%ld philosophe %ld has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo[i].for_writing);
}

void taking_next_fork(t_philo_info *philo)
{
    pthread_mutex_lock(fork);
    pthread_mutex_lock(&philo[i].for_writing)
    printf("%ld philosophe %ld has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo[i].for_writing);
}

void x_time_musteat(t_philo_info)
{
    if(philo->args->x_time_musteat)
    {
        philo->args->x_time_musteat--;
        if(x_time_musteat = 0)
            return ;
    }
}
void is_eating(t_philo_info *philo)
{
    takefork(philo);
    take_next_fork(philo);
    pthread_mutex_lock(philo[i].for_writing);
    printf("%ld philosophe %ld is eating\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo[i].for_writing);
    pthread_mutex_unlock(philo[i].fork);
    pthread_mutex_unlock(philo[i].next_fork);
    x_time_musteat(philo);
}