# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 16:50:07 by vfil              #+#    #+#              #
#    Updated: 2017/12/17 17:26:36 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	c_island

MAIN	=	main.c

SRC		=	func.c ft_split.c

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(MAIN) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
