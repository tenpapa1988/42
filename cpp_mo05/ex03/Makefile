# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 10:15:15 by yussaito          #+#    #+#              #
#    Updated: 2025/06/20 15:12:28 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
	   Intern.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re