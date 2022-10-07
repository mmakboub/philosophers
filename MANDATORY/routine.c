/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:20 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/07 17:28:36 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void    *routine(void *argv)
{
    t_philo_info    *philo;
    philo = (t_philo_info *)argv;
    // printf("HI\n");
    printf("pp -- %d\n",philo->args->nbr_philo);
    if(philo->index % 2 == 0)
        get_break(philo->args->eat); 
    while(1)
    {
        //checking_death(philo);
        if(!is_eating(philo))
            break;
        is_sleeping(philo);
        is_thinking(philo);
    }
    return (NULL);
}

int   creatthreads(t_compstargs   *argphilo, t_philo_info    *philos)
{
    int i;
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        philos[i].start = getting_time();
        philos[i].last_meal = philos[i].start;
        if(pthread_create(&philos[i].philo, NULL,  &routine, &philos[i]) < 0)
            return(printf("the tread wasn't created \n"), 0);
        i++;
    }
     i = 0;
    while(i < argphilo->nbr_philo)
    {
        if((pthread_join((philos[i].philo), NULL))  != 0)
            return(printf("the tread wasn't joined \n"), 0);
        i++;
    }
    return (1);
}