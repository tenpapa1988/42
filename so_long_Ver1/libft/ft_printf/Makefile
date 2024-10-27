# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:55:48 by yussaito          #+#    #+#              #
#    Updated: 2024/10/27 12:37:11 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
HDRS = pf_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../libft/libft.a
SRCS = ./ft_print_char.c \
		./ft_print_deci.c \
		./ft_print_hex_low_x.c \
		./ft_print_hex_p.c \
		./ft_print_hex_up_x.c \
		./ft_print_int.c \
		./ft_print_str.c \
		./ft_printf.c \
		./ft_utoa.c \

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C ../libft
	ar rc $(NAME) $(LIBFT) $(OBJS)
	ranlib $(NAME)

all : $(NAME)

clean :
	make clean -C ../libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ../libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re