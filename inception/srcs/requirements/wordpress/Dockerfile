# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:57:23 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 10:57:24 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:12

RUN apt-get update && apt-get install -y \
    php php-fpm php-mysql curl wget tar unzip mariadb-client \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/bin/bash", "-c", "/setup.sh && php-fpm -F"]
