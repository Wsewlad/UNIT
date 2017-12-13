# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 14:55:49 by vfil              #+#    #+#              #
#    Updated: 2017/12/12 20:19:02 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	gn_line

MAIN	=	main.c

SRC		=	GNL/get_next_line.c

FLAFS	=	-Wall -Wextra -Werror

LIBS	=	-L GNL/libft -lft -I GNL

all: $(NAME)

$(NAME):
	cd GNL/libft && make
	gcc $(FLAGS) -o $(NAME) $(MAIN) $(SRC) $(LIBS)

clean:
	cd GNL/libft && make clean

fclean: clean
	cd GNL/libft && make fclean
	rm $(NAME)

re: fclean all
