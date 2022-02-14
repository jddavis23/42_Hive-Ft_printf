# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:19:40 by jdavis            #+#    #+#              #
#    Updated: 2022/02/14 16:33:06 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a

INCLUDES = libft/

CC = gcc -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c $(SRC) -I ft_printf.h -I $(INCLUDES) -L libft/ -lft
	@ar -r $(NAME) $(OBJ) -L libft/ -lft

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
