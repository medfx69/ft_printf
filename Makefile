# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:06:23 by mait-aad          #+#    #+#              #
#    Updated: 2021/12/13 15:19:21 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = c.c\
	ft_printf.c\
	i.c\
	p.c\
	s.c\
	X.c\
	lx.c\
	persent.c\
	u.c

OBJ = c.o\
	ft_printf.o\
	i.o\
	p.o\
	s.o\
	X.o\
	lx.o\
	persent.o\
	u.o
all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all
