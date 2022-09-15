/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_from_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:34:45 by mmakboub          #+#    #+#             */
/*   Updated: 2022/09/15 19:57:17 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
//get ruturn from a thread
void    *roll_dice()
{
    int value = (rand()  % 6) + 1;
    int *res = malloc(sizeof (int));
    *res = value;
    printf("thread res : %p\n", res);
    return (void *)res;
}

int main()
{
    int *res;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL) != 0)
        return(1);
    if(pthread_join(th, (void **) &res)!= 0)
        return(2);
    printf("main res : %p\n", res);
    printf("result : %d\n", *res);
    free(res);
}