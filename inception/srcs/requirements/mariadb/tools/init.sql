# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sql                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 09:57:27 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 14:28:29 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREATE DATABASE IF NOT EXISTS wordpress;

CREATE USER IF NOT EXISTS 'wpuser'@'%' IDENTIFIED BY 'wppass';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wpuser'@'%';

CREATE USER IF NOT EXISTS 'admin42'@'%' IDENTIFIED BY 'rootpass';
GRANT ALL PRIVILEGES ON *.* TO 'admin42'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;
