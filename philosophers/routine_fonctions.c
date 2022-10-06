/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fonctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:57:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/06 17:27:49 by mmakboub         ###   ########.fr       */
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
    pthread_mutex_lock(philo->args->for_writing)
    printf("%ld philosophe %ld is sleeping\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing)
    
}

void is_thinking(t_philo_info *philo)
{
    pthread_mutex_lock(philo->args->for_writing)
    printf("%ld philosophe %ld is thinking\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing)
}

void taking_fork(t_philo_info *philo)
{
    pthread_mutex_lock(philo->fork);
    pthread_mutex_lock(philo->args->for_writing)
    printf("%ld philosophe %ld has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
}

void taking_next_fork(t_philo_info *philo)
{
    pthread_mutex_lock(philo->next_fork);
    pthread_mutex_lock(philo->args->for_writing)
    printf("%ld philosophe %ld has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
}

void x_time_musteat(t_philo_info *philo)
{
    if(philo->args->x_time_musteat)
    {
        philo->nbrofeats++;
        if(philo->args->nbr_philo * philo->args->x_time_musteat == philo->nbrofeats)
            break;
    }
}
void is_eating(t_philo_info *philo)
{
    takefork(philo);
    take_next_fork(philo);
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %ld is eating\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
    pthread_mutex_unlock(philo->fork);
    pthread_mutex_unlock(philo->next_fork);
    x_time_musteat(philo);
}
//for writing has change it's position from struct 2 to struct 1 !!!!!!!!!!!
//musteat * n_philo should be equal to our variable nbrofeats