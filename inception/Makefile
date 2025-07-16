# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 09:41:39 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 10:08:36 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = inception

all: build up

build:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env build

up:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up -d

down:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env down

clean:
	docker system prune -af --volumes

fclean: down clean

re: fclean all

.PHONY: all build up down clean fclean re
