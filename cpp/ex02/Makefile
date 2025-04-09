# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 23:57:34 by yussaito          #+#    #+#              #
#    Updated: 2025/04/09 05:19:19 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamjobs
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re