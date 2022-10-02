/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:14:36 by mmakboub          #+#    #+#             */
/*   Updated: 2022/10/02 00:39:09 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t *key;

void    *routine(void *arg)
{
    int *x;
    pthread_mutex_lock(key);
    x = (int *)arg;
    *x += 1;
    printf("im philo %d\n", *x);
    pthread_mutex_unlock(key);
    // sleep(1);
    return NULL;
}
int main()
{
    int i;
    pthread_t th[4];
    int x; 
    x = 0;
    i = 0;
    key = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(key, NULL);
    while(i < 4)
    {
        pthread_create(&th[i], NULL, &routine, &x);
        i++;        
    }
    while(1);
}
