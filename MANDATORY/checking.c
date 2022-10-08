/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:14 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/08 16:36:41 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void checking_death(t_philo_info *philo)
{
    while (1)
    {
        if(getting_time() - philo[philo->index].last_meal > philo->args->die)
        {
            pthread_mutex_lock(philo->args->for_writing);
            printf("%ld ms philosophe %d is died\n", execution_time(philo) , philo->index);
            philo->args->timehascome = 0;
            //philo->status = false;
            return ;
        }
    }
}