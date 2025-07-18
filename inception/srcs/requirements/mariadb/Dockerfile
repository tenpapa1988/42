# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 09:56:35 by yussaito          #+#    #+#              #
#    Updated: 2025/07/17 13:16:19 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:12

RUN apt update && \
    apt install -y mariadb-server && \
    sed -i "s/127.0.0.1/0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf && \
    rm -rf /var/lib/apt/lists/*

COPY tools/init.sql /docker-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld_safe"]
