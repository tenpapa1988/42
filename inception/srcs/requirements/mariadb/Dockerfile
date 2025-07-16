# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 09:56:35 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 09:57:19 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:12

RUN apt update && \
    apt install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ENV MYSQL_USER=${MYSQL_USER}
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}
ENV MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}

COPY tools/init.sql /docker-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld_safe"]
