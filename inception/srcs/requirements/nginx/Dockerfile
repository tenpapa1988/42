# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:56:42 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 10:56:43 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:12

RUN apt update && \
    apt install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

COPY conf/default.conf /etc/nginx/sites-available/default
COPY tools/ssl.sh /ssl.sh

RUN chmod +x /ssl.sh && /ssl.sh

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
