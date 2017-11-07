# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 14:32:29 by vfil              #+#    #+#              #
#    Updated: 2017/10/25 15:13:06 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_display_file
SRC		=	main.c
FLAGS	=	-Wall -Werror -Wextra

.PHONY: all
all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
