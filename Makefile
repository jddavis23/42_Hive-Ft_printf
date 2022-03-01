# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:19:40 by jdavis            #+#    #+#              #
#    Updated: 2022/03/01 18:08:20 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = libft/

CC = gcc -Wall -Wextra -Werror -I libft/

SRC = solve_c_s.c
SRC += va_test.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	#@make -C libft/ fclean && make -C libft/
	#@$(CC) -c $(SRC) -I ft_printf.h
	#@ar -r $(NAME) $(OBJ) libft/*.o
	$(CC) -c -I ./includes $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
