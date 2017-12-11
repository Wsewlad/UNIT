# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 14:55:49 by vfil              #+#    #+#              #
#    Updated: 2017/12/11 15:11:21 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gn_line

MAIN	=	main.c

SRC		=	get_next_line.c

FLAFS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cd libft && make
	gcc $(FLAGS) -o $(NAME) $(MAIN) $(SRC) -L libft -lft

clean:
	cd libft && make clean

fclean: clean
	cd libft && make fclean
	rm $(NAME)

re: fclean all
