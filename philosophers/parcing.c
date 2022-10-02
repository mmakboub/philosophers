/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:13:29 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/03 00:38:55 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
void    get_time(int timing)
{
    
}
int     check_digit(char **argument)
{
    int i;
    int j;

    i = 1;
    while(argument[i])
    {
        j = 0;
        while(argument[i][j])
        {
            if(!ft_isdigit(argument[i][j]))
                return(errorinargument());
            j++;
        }
        i++;
    }
    return(1);
}
void    initialiaze_all(t_compstargs   *argphilo, t_philo_info    *philo, char **av, int ac)
{
    int i;
    
    i = 0;
    argphilo->nbr_philo = ft_atoi(av[1]);
    argphilo->die = ft_atoi(av[2]);
    argphilo->eat = ft_atoi(av[3]);
    argphilo->sleep = ft_atoi(av[4]);
    argphilo->x_time_musteat = 0;
    argphilo->start = get_time()
    if(av[5])
            argphilo->x_time_musteat = ft_atoi(av[5]);
    argphilo->philo = (pthread_t *)malloc(sizeof(pthread_t) * argphilo->nbr_philo);
    if(!argphilo->philo)
        return(0);
    while(i < argphilo->nbr_philo)
    {
        philo[i].index = i + 1;
        philo[i].status = 1;//in order to check the status of philosophers
        philo[i].args = argphilo;
    }
    return(1);
}