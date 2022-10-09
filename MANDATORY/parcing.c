/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:13:29 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/09 20:06:41 by mmakboub         ###   ########.fr       */
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
                return(write(1, "invalide argument\n", 17), 0);
            j++;
        }
        if(ft_atoi(argument[i]) > 2147483647 || ft_atoi(argument[i]) < -2147483648)
        {
            write (1, "invalide argument\n", 17);
		    return(0);}
        i++;
    }
    return(1);
}
