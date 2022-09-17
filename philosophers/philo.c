/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:27:57 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/17 23:17:03 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int main(int ac, char **av)
{
    t_compstargs    argphilo;
    // if(ac != 6 && ac != 5)
    //     errorinargument();
    if(ac == 5 || ac == 6)
    {
        check_digit(av);
        initialiaze_argv(&argphilo, av, ac);
    }
    else
        errorinargument();
}
