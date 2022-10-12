/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:14 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/12 13:05:18 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checking_death(t_philo_info *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (getting_time() - philo[i].last_meal >= philo->args->die)
		{
			pthread_mutex_lock(philo->args->for_writing);
			printf("%ld ms philosopher %d is died\n", \
					execution_time(philo), philo[i].index);
			philo->args->timehascome = 0;
			return ;
		}
		if (philo->args->done)
			break ;
		i = (i + 1) % philo->args->nbr_philo;
		usleep(100);
	}
}
