NAME = ft_printf.a

SRCS = ./ft_print_char.c \
	./ft_print_deci.c \
	./ft_print_hex_low_x.c \
	./ft_print_hex_p.c \
	./ft_print_hex_up_x.c \
	./ft_print_int.c \
	./ft_print_str.c \
	./ft_printf.c \
	./ft_utoa.c \

OBJS = $(SRCS:.c=.o)

HDRS = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re