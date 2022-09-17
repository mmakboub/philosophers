/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/17 20:06:21 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"
int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

void     check_digit(char **argument)
{
    int i;
    int j;

    i = 0;
    while(argument[i])
    {
        j = 0;
        while(argument[i][j])
        {
            if(!ft_isdigit(argument[i][j]))
            {
                write(1, "invalid argument\n", 18);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
void    check_argument( char **argv, int ac)
{
    int i;
    i = 1;
    check_digit(argv);
    while(argv[i])
    {
        if(ft_atoi(argv[i]) <= 0)
            errorinargument()
        i++;
    }
}
void    initialiaze_argv(t_compstargs   *argphilo, char **argv, int ac)
{
        argphilo->nbr_philo = ft_atoi(av[1]);
        argphilo->die = ft_atoi(av[2]);
        argphilo->eat = ft_atoi(av[3]);
        argphilo->sleep = ft_atoi(av[4]);
        argphilo->nb_time_philo_musteat = 0; 
        if (av[5])
            argphilo->nb_time_philo_musteat = ft_atoi(av[5]);
}

int main(int ac, char **av)
{
    t_compstargs    argphilo;
    if(ac != 6 || ac != 5)
        errorinargument();
    else if(ac == 5 || ac == 6)
    {
        check_argument(av, ac);
        initialiaze_argv(&argphilo, av, ac);
    }
}
