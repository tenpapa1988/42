# Standard
NAME 				= push_swap

# Directories
LIBFT 				= ./libft/libft.a
FT_PRINTF			= ./ft_printf/ft_printf.a
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/

# Compiler and CFlag
CC					= gcc
CFLAGS 				= -Wall -Wextra -Werror -I ./inc/ -I ./libft/ -I ./ft_printf/
RM					= rm -f

SRCS 				= $(SRC_DIR)a_to_b.c \
					$(SRC_DIR)b_to_a.c \
					$(SRC_DIR)errors_handle.c \
					$(SRC_DIR)push_swap.c \
					$(SRC_DIR)push.c \
					$(SRC_DIR)rerotate.c \
					$(SRC_DIR)rotate.c \
					$(SRC_DIR)sort_stacks.c \
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
$(NAME):			$(OBJS) $(LIBFT) $(FT_PRINTF)
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
					make -C ./libft

$(FT_PRINTF):
					make -C ./ft_printf
					
# Standard targets
all:				$(NAME)

clean:
					make clean -C libft
					make clean -C ft_printf
					@$(RM) -r $(OBJ_DIR)

fclean: 			clean
					make fclean -C ./libft
					make fclean -C ./ft_printf
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re $(LIBFT) $(FT_PRINTF)