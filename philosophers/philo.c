/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/18 22:48:27 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
/*void    creatthreads(t_compstargs   *argphilo)
{
    int i;
    i = 0;
    while(i < argphilo-> nbr_philo)
    {
        i++;//i is the index of philo
    }
    
}*/
int main(int ac, char **av)
{
    t_compstargs    argphilo;
    
    if(ac == 5 || ac == 6)
    {
        if(!check_digit(av))
            errorinargument();
        initialiaze_argv(&argphilo, av, ac);
        //creat_threads(&argphilo)
    }
    else
        errorinargument();
}
