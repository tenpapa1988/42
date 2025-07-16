# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sql                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 09:57:27 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 09:57:36 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};

CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';

CREATE USER IF NOT EXISTS 'admin42'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'admin42'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;
