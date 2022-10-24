# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 11:29:09 by jdavis            #+#    #+#              #
#    Updated: 2022/10/24 11:25:46 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
CC = gcc -Wall -Wextra -Werror -L.

all: $(NAME) t1

$(NAME):
	@make -C ../ fclean &&  make -C ../

t1:
	$(CC) ../libftprintf.a main.c
