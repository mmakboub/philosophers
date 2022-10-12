/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/12 13:03:00 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	main(int ac, char **av)
{
	t_compstargs	*argphilo;
	t_philo_info	*philo;

	if (ac == 5 || ac == 6)
	{
		if (!check_digit(av))
			return (0);
		argphilo = (t_compstargs *)malloc(sizeof(t_compstargs));
		philo = (t_philo_info *)malloc(sizeof(t_philo_info) * ft_atoi(av[1]));
		if (!argphilo || !philo)
			return (0);
		if (!(initialiaze_all(argphilo, philo, av)) \
			|| !(init_fork(philo)) || !(init_next_fork(philo)))
			return (0);
		creatthreads(argphilo, philo);
		destroy_all(philo, argphilo);
	}
	else
		errorinargument();
	return (1);
}
