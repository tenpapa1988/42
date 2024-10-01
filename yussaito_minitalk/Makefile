# File Name
NAME_SERVER			= server
NAME_CLIENT			= client

# Directory
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/
LIBFT				= ./libft/libft.a

# Compiler and CFlag
CC					= clang
CFLAGS				= -Wall -Wextra -Werror
RM					= rm -f

# Object File and Source File
SRCS				= $(SRC_DIR)server.c $(SRC_DIR)client.c

# Generate Object File
$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

# Build
all:				$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_DIR)server.o $(LIBFT)
					$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_DIR)server.o -L libft -lft

$(NAME_CLIENT):		$(OBJ_DIR)client.o $(LIBFT)
					$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_DIR)client.o -L libft -lft

# Library Build
$(LIBFT):			
					make -C libft

# Standard
clean:				
					$(RM) -r $(OBJ_DIR)
					make -C libft clean

fclean:				clean
					$(RM) $(NAME_SERVER) $(NAME_CLIENT)
					make -C libft fclean

re:					fclean all

.PHONY:				all clean fclean re
