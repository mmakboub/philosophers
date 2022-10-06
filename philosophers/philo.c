/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/06 13:01:20 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
void    *routine(void *argv)
{
    t_philo_info    *philo;
    philo = (t_philo_info *)argv;
    if(philo->index % 2 == 0)
        get_break(philo->args->eat); 
    while(1)
    {
       is_eating(philo);
       is_sleeping(philo);
       is_thinking(philo);
    }
}
int   creatthreads(t_compstargs   *argphilo, t_philo_info    *philos)
{
    int i;
    t_compstargs *philoinfo;
    i = 0;
    philos[i].start = getting_time();
    while(i < argphilo->nbr_philo)
    {
        //to do : initialize last_meal in the least of is_eating function
        int *a = malloc(sizeof(int));
        *a = i;
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

int init_mutex(t_philo_info *philo)
{
    int i = 0;
    while(i < philo->args->nbr_philo)
    {
        philo[i].for_writing = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(!philo[i].for_writing)
            return(0);
        pthread_mutex_init(philo[i].for_writing, NULL);
        i++;
    }
    /*int i = 0;  this party will be done when one of philosophers die
    while(i < philo->args->nbr_philo)
    {
        philo[i].death_of_philo = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        if(!philo[i].death_of_philo)
            return(0);
        pthread_mutex_init(philo[i].death_of_philo, NULL);
        i++;
    }
    return(1);*/
}

int init_next_fork(t_philo_info *philo)
{
    int i = 0;
    while(i < philo->args->nbr_philo)
    {
        //pthread_mutex_init(philo[i].fork, NULL);
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
        if(!philo[i].fork)
            return(0);
        pthread_mutex_init(philo[i].fork, NULL);
        i++;
    }
    return(1);
}
int init_mutex()
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
        //printf("%d\n", ac);
        creatthreads(argphilo, philo);
    }
    else
        errorinargument();
    return(1);
}
