/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/02 01:48:13 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
void    *routine(void *argv)
{
    
    if((*(int *)argv + 1) % 2 == 0)
        usleep(10000);
    while(1)
    {
        
        printf("time !!ms philo %d has taking a fork\n", *(int *)argv + 1);
        printf("time !!ms philo %d has takin a fork\n", *(int *)argv + 1);
        printf("time !!ms philo %d is eating\n", *(int *)argv + 1);
        sleep(2);
        printf("time !!ms philo %d is sleeping\n", *(int *)argv + 1);
        sleep(2);
        printf("time !!ms philo %d is thinking\n", *(int *)argv + 1);
    }
    return NULL;
}
void    creatthreads(t_compstargs   *argphilo)
{
    int i;
    t_compstargs *philoinfo;
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        //printf("hi\n");
        pthread_create(&(argphilo->philo[i]), NULL,  &routine, a);
        i++;
    }
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        pthread_join((argphilo->philo[i]), NULL);
        i++;
    }
    
}
int init_next_fork(t_philo_info *philo)
{
    t_compstargs *argphilo;
    int i = 0;
    while(i < argphilo->nbr_philo)
    {
        philo[i].init_next_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(!philo[i].init_next_fork)
            return(0);
        pthread_mutex_init(philo[i].init_next_fork, NULL);
        i++;
    }
    return(1);
}
int init_fork(t_philo_info *philo)
{
    t_compstargs *argphilo;
    int i = 0;
    while(i < argphilo->nbr_philo)
    {
        philo[i].fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(!philo[i].fork)
            return(0);
        pthread_mutex_init(philo[i].fork, NULL);
        i++;
    }
    return(1);
}
int intiatialize_all(t_philo_info *info)
{
    t_compstargs    *argphilo;
    int i;
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        philo->index = i + 1;
        
        
    }
}
int main(int ac, char **av)
{
    t_compstargs    *argphilo;

    if (ac == 5 || ac == 6)
    { 
        //printf("%d\n", ac);
        if(!check_digit(av))
            errorinargument();
        argphilo = (t_compstargs *)malloc(sizeof(t_compstargs));
        initialiaze_argv(argphilo, av, ac);
        argphilo->philo = (pthread_t *)malloc(sizeof(pthread_t) * argphilo->nbr_philo); 
        creatthreads(argphilo);
        //while(1);
    }
    else
        errorinargument();
}
