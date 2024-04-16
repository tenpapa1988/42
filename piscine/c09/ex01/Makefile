NAME = libft.a
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = srcs
SOURCES = $(wildcard $(TARGET)/*.c)
HEADERS = includes
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c
	$(COMPILER) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re