# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 16:32:39 by mmakboub          #+#    #+#              #
#    Updated: 2022/10/10 14:06:58 by mmakboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
FONCTIONS = ./MANDATORY/philo.c\
			./MANDATORY/parcing.c\
			./MANDATORY/helpfullfonctions.c\
			./MANDATORY/initialisation.c\
			./MANDATORY/routine_fonctions.c\
			./MANDATORY/routine.c\
			./MANDATORY/timing.c\
			./MANDATORY/checking.c
	
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = ./MANDATORY/philosophers.h

OBJS = $(FONCTIONS:.c=.o)


all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) 

re: fclean all