/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:35:20 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/08 11:27:57 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void get_break(long sleep_time)
{
    long wake_up;
    wake_up = getting_time() + sleep_time;
    while(getting_time() < wake_up)
        usleep(50);
}

long    getting_time(void)
{
    struct timeval timing;
    gettimeofday(&timing, NULL);
    return((timing.tv_sec * 1000) + (timing.tv_usec / 1000));
}

long execution_time(t_philo_info *philo)
{
    long exct_time;
    
    exct_time = getting_time() - philo->start ;
    return(exct_time);
}
