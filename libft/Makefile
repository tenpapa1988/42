NAME = libft.a

SRC = 	./ft_atoi.c 		\
		./ft_bzero.c 		\
		./ft_calloc.c 		\
		./ft_isalnum.c 		\
		./ft_isalpha.c 		\
		./ft_isascii.c 		\
		./ft_isdigit.c 		\
		./ft_isprint.c 		\
		./ft_itoa.c 		\
		./ft_memccpy.c 		\
		./ft_memchr.c 		\
		./ft_memcmp.c 		\
		./ft_memcpy.c 		\
		./ft_memmove.c 		\
		./ft_putchar.c 		\
 		./ft_putstr.c 		\
 		./ft_putnbr.c 		\
		./ft_split.c 		\
		./ft_strcat.c 		\
		./ft_strchr.c 		\
		./ft_strcpy.c 		\
		./ft_strdup.c 		\
		./ft_strjoin.c 		\
		./ft_strlcat.c 		\
		./ft_strlcpy.c 		\
		./ft_strlen.c 		\
		./ft_strmapi.c 		\
		./ft_strncat.c 		\
		./ft_strncpy.c 		\
		./ft_strtrim.c 		\
		./ft_substr.c 		\
		./ft_tolower.c 		\
		./ft_toupper.c 		\
		./ft_printf.c 		\
 
OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC) 
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all