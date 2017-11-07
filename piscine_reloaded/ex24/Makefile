# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:38:04 by vfil              #+#    #+#              #
#    Updated: 2017/10/25 19:37:13 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME	=	libft.a
SRC		=	srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OSRC	=	ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
HEAD	=	includes/

.PHONY: all
all:
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEAD)
	ar rc $(LNAME) $(OSRC)

.PHONY: clean
clean:
	rm -f *.o

.PHONY: fclean
fclean: clean
	rm -f $(LNAME)

.PHONY: re
re: fclean all
