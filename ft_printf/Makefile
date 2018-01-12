# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 15:07:48 by vfil              #+#    #+#              #
#    Updated: 2018/01/11 17:02:13 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c

OSRC	=	$(SRC:.c=.o)

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC)

%.o : %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
