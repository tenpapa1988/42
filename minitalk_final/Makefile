# File Name
NAME_SERVER			= server
NAME_CLIENT			= client

# Directory
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/
FT_PRINTF			= ./ft_printf/libftprintf.a

# Compiler and CFlag
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I ./inc/
RM					= rm -f

# Object File and Source File
SRCS				= $(SRC_DIR)server.c $(SRC_DIR)client.c

# Generate Object File
$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

# Build
all:				$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_DIR)server.o $(FT_PRINTF)
					$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_DIR)server.o -L ft_printf -lftprintf
$(NAME_CLIENT):		$(OBJ_DIR)client.o $(FT_PRINTF)
					$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_DIR)client.o -L ft_printf -lftprintf

# ft_printf Build
$(FT_PRINTF):			
					make -C ft_printf

# Standard
clean:				
					$(RM) -r $(OBJ_DIR)
					make -C ft_printf clean

fclean:				clean
					$(RM) $(NAME_SERVER) $(NAME_CLIENT)
					make -C ft_printf fclean

re:					fclean all

.PHONY:				all clean fclean re
