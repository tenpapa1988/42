# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:55:48 by yussaito          #+#    #+#              #
#    Updated: 2024/05/12 13:26:09 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HDRS = pf_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(HDRS)
LIBFT = ./libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft
	cp ${LIBFT} ${NAME}
	ar rc $(NAME) $^
	ranlib $(NAME)

all : $(NAME)

clean :
	make clean -C libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re