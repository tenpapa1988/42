#Standard
NAME				= philo

# Directories
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/

# Compiler and CFlag
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I ./inc/ -O3 -pthread -g

SRCS 				= $(SRC_DIR)main.c \
					$(SRC_DIR)utils.c \
					$(SRC_DIR)init.c \
					$(SRC_DIR)threads.c \
					$(SRC_DIR)monitoring.c \
					$(SRC_DIR)routine.c


OBJS				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Compile object files from source files
$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

# Build the executable
$(NAME):			$(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Standard targets
all:				$(NAME)

clean:
					-rm -r $(OBJ_DIR)

fclean: 			clean
					-rm $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
