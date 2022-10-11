/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_error&free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:35:42 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/11 23:39:04 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	errorinargument(void)
{
	write(1, "invalide arguments\n", 17);
	return (0);
}

void	destroy_all(t_philo_info *philo, t_compstargs *arg)
{
	int	i;

	i = 0;
	while (i < arg->nbr_philo)
	{
		pthread_mutex_destroy(philo[i].fork);
		free(philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(arg->for_writing);
	free(arg->for_writing);
	free(philo);
	free(arg);
}
