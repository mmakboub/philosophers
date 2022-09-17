/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpfullfonctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:18:43 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/17 22:47:44 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int ft_atoi(char *str)
{
    int i;
    int res;
    int signe = 1;
    i = 0;
    signe = 1;
    res = 0;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            signe = -1;
        i++;
    }
    while(str[i] >= 0 && str[i] <= 9)
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return(signe * res);
}
int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}
