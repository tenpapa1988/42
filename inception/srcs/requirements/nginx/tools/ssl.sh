# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ssl.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:53:46 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 10:53:49 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

mkdir -p /etc/ssl/certs /etc/ssl/private

openssl req -x509 -nodes -days 365 \
  -newkey rsa:2048 \
  -keyout /etc/ssl/private/nginx.key \
  -out /etc/ssl/certs/nginx.crt \
  -subj "/C=JP/ST=Tokyo/L=Tokyo/O=42Tokyo/CN=${DOMAIN_NAME}"
