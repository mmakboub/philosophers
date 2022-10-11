/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:20 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/11 21:37:35 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	x_time_musteat(t_philo_info *philo)
{
	if (philo->args->x_time_musteat > 0)
	{
		philo->args->nbrofeats++;
		if (philo->args->nbr_philo * philo->args->x_time_musteat \
			== philo->args->nbrofeats)
		{
			philo->args->done = 1;
			return (0);
		}
	}
	return (1);
}

void	*routine(void *argv)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)argv;
	if (philo->index % 2 == 0)
		get_break(30);
	while (1)
	{
		if (!philo->args->timehascome)
			break ;
		if (!is_eating(philo))
			break ;
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (NULL);
}

int	creatthreads(t_compstargs *argphilo, t_philo_info *philos)
{
	int	i;

	i = 0;
	while (i < argphilo->nbr_philo)
	{
		philos[i].start = getting_time();
		if (pthread_create(&philos[i].philo, NULL, &routine, &philos[i]) < 0)
			return (printf("the tread wasn't created \n"), 0);
		i++;
	}
	i = 0;
	while (i < argphilo->nbr_philo)
	{
		pthread_detach(philos[i].philo);
		i++;
	}
	checking_death(philos);
	return (1);
}
