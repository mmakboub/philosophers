/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/04 00:22:54 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
void    *routine(void *argv)
{
    long time;
    time = get_time();
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
int   creatthreads(t_compstargs   *argphilo, t_philo_info    *philos)
{
    int i;
    t_compstargs *philoinfo;
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        //printf("hi\n");
        if(pthread_create(&(philos->philo[i]), NULL,  &routine, a) < 0)
            return(printf("the tread wasn't created \n"), 0);
        i++;
    }
    i = 0;
    while(i < argphilo->nbr_philo)
    {
        if(!(pthread_join((philos->philo[i]), NULL)))
            return(printf("the tread wasn't joined \n"), 0);
        i++;
    }
    return (1);
}
int init_next_fork(t_philo_info *philo)
{
    int i = 0;
    while(i < philo->args->nbr_philo)
    {
        // pthread_mutex_init(philo[i].fork, NULL);
        philo[i].next_fork = philo[(i + 1) % philo->args->nbr_philo].fork;
        printf("mariam %p\n", philo[i].next_fork);
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
        if(!philo[i].fork)
            return(0);
        pthread_mutex_init(philo[i].fork, NULL);
        i++;
    }
    return(1);
}

int main(int ac, char **av)
{
    t_compstargs    *argphilo;
    t_philo_info    *philo;

    if (ac == 5 || ac == 6)
    { 
        if(!check_digit(av))
            errorinargument();
        argphilo = (t_compstargs *)malloc(sizeof(t_compstargs));
        philo = (t_philo_info *)malloc(sizeof(t_philo_info));
        if(!(initialiaze_all(argphilo, philo, av, ac)) || !(init_fork(philo)) || !(init_next_fork(philo)))
            return(0);
        printf("%d\n", ac);
        creatthreads(argphilo, philo);
    }
    else
        errorinargument();
    return(1);
}
