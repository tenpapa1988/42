# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 12:26:28 by yussaito          #+#    #+#              #
#    Updated: 2024/11/17 13:16:46 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# File Name
NAME				= so_long

# Directory
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/
LIBFT				= ./libft/libft/libft.a
FT_PRINTF			= ./libft/ft_printf/libftprintf.a
MINILIBX			= ./minilibx-linux/libmlx.a

# Compiler and CFlag
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I ./inc/
RM					= rm -f
FRAMEWORK			= -L ./minilibx-linux -lmlx -lXext -lX11 -lm

# Object File and Source File
SRCS				= $(SRC_DIR)main.c \
					  $(SRC_DIR)get_map.c \
					  $(SRC_DIR)get_map2.c \
					  $(SRC_DIR)get_map3.c \
					  $(SRC_DIR)get_map4.c \
					  $(SRC_DIR)get_map_utils.c \
					  $(SRC_DIR)get_map_utils2.c \
					  $(SRC_DIR)get_image_utils.c \
					  $(SRC_DIR)hook_functions.c \
					  
OBJS 				= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Generate Object File
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

# Build
all:				$(NAME)

$(NAME):			$(OBJS) $(FT_PRINTF) $(LIBFT) $(MINILIBX)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT) $(FRAMEWORK)


# libft Build
$(LIBFT):			
					make -C ./libft/libft
					
# ft_printf Build
$(FT_PRINTF):			
					make -C ./libft/ft_printf

# MiniLibX Build
$(MINILIBX):
					make -C ./minilibx-linux

# Standard
clean:
					$(RM) -r $(OBJ_DIR)
					make clean -C ./libft/libft
					make clean -C ./libft/ft_printf
					make clean -C ./minilibx-linux

fclean:				clean
					$(RM) $(NAME)
					make fclean -C ./libft/libft
					make fclean -C ./libft/ft_printf

re:					fclean all

.PHONY:				all clean fclean re