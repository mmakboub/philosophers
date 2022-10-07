/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_fonctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:57:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/07 14:12:49 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

// time imta creater thread
// time for last time philo start eating
void is_sleeping(t_philo_info *philo)
{
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %d is sleeping\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
    
}

void is_thinking(t_philo_info *philo)
{
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %d is thinking\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
}

void taking_fork(t_philo_info *philo)
{
    pthread_mutex_lock(philo->fork);
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %d has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
}

void taking_next_fork(t_philo_info *philo)
{
    pthread_mutex_lock(philo->next_fork);
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %d has taken a fork\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
}

int x_time_musteat(t_philo_info *philo)
{
    if(philo->args->x_time_musteat > 0)
    {
        philo->args->nbrofeats++;
        if(philo->args->nbr_philo * philo->args->x_time_musteat == philo->args->nbrofeats)
            return (0);
    }
    return (1);
} 
int is_eating(t_philo_info *philo)
{
    taking_fork(philo);
    taking_next_fork(philo);
    pthread_mutex_lock(philo->args->for_writing);
    printf("%ld philosophe %d is eating\n", (getting_time() - philo->start) , philo->index);
    pthread_mutex_unlock(philo->args->for_writing);
    pthread_mutex_unlock(philo->fork);
    pthread_mutex_unlock(philo->next_fork);
    if(!x_time_musteat(philo))
        return(0);
    return(1);
}
//for writing has change it's position from struct 2 to struct 1 !!!!!!!!!!!
//musteat * n_philo should be equal to our variable nbrofeats