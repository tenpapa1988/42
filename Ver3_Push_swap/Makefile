# Standard
NAME 				= push_swap

# Directories
LIBFT 				= ./libft/libft.a
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/

# Compiler and CFlag
CC					= cc
CFLAGS 				= -Wall -Wextra -Werror -I ./inc/ -I ./libft/
RM					= rm -f

SRCS 				= $(SRC_DIR)a_to_b.c \
					$(SRC_DIR)b_to_a.c \
					$(SRC_DIR)errors_handle.c \
					$(SRC_DIR)ft_printf.c \
					$(SRC_DIR)push_swap.c \
					$(SRC_DIR)push.c \
					$(SRC_DIR)rerotate.c \
					$(SRC_DIR)rotate.c \
					$(SRC_DIR)sort_stacks.c \
					$(SRC_DIR)sort_stacks2.c \
					$(SRC_DIR)sort_three.c \
					$(SRC_DIR)split.c \
					$(SRC_DIR)stack_analysis.c \
					$(SRC_DIR)stack_init.c \
					$(SRC_DIR)stack_init2.c \
					$(SRC_DIR)swap.c \

OBJS 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Compile object files from source files
$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@
					
# Build the executable
$(NAME):			$(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
					make -C ./libft

# Standard targets
all:				$(NAME)

clean:
					make clean -C libft
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					make fclean -C ./libft
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re $(LIBFT)