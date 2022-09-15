/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:45:04 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/15 16:05:51 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void    *routine()
{
    printf("test from threeads\n");
    sleep(3);
    printf("end of testing\n");
    return(NULL);
    
} 
int main(void)
{
    pthread_t   var;
    pthread_t   var2;
    if(pthread_create(&var, NULL, &routine, NULL)) //creat thread
        return (1);
    if(pthread_create(&var2, NULL, &routine, NULL)) //creat thread
        return (2);
    if(pthread_join(var, NULL)) // wait untill the thread finish it's execution
        return(3);
    if(pthread_join(var2, NULL))
        return(4);
    
}
