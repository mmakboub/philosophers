/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:13:29 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/18 22:33:11 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
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
                errorinargument();
            j++;
        }
        i++;
    }
    return(1);
}
void    initialiaze_argv(t_compstargs   *argphilo, char **av, int ac)
{
        argphilo->nbr_philo = ft_atoi(av[1]);
        argphilo->die = ft_atoi(av[2]);
        argphilo->eat = ft_atoi(av[3]);
        argphilo->sleep = ft_atoi(av[4]);
        argphilo->nb_time_philo_musteat = 0; 
        if (av[5])
            argphilo->nb_time_philo_musteat = ft_atoi(av[5]);
}