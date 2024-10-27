# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 12:38:28 by yussaito          #+#    #+#              #
#    Updated: 2024/10/27 12:55:16 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# File Name
NAME = libft.a

# Object File and Source File
SRCS = ./ft_atoi.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memchr.c \
		./ft_memset.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_putchar_fd.c \
		./ft_putendl_fd.c \
		./ft_putstr_fd.c \
		./ft_putnbr_fd.c \
		./ft_split.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strdup.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlcpy.c \
		./ft_strlen.c \
		./ft_strmapi.c \
		./ft_strncmp.c \
		./ft_strnstr.c \
		./ft_strtrim.c \
		./ft_substr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_lstnew.c \
		./ft_lstadd_front.c \
		./ft_lstsize.c \
		./ft_lstlast.c \
		./ft_lstadd_back.c \
		./ft_lstdelone.c \
		./ft_lstclear.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./get_next_line.c \
		./get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HDRS = libft.h

# Compiler and CFlag
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
		ar rc $(NAME) $^
		ranlib $(NAME)

# Rule to create object files, with dependency on the header file
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the static library
fclean: clean
		rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus