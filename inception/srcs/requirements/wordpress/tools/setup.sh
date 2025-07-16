# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 10:53:22 by yussaito          #+#    #+#              #
#    Updated: 2025/07/16 10:53:41 by yussaito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

until mysqladmin ping -hmariadb -u$MYSQL_USER -p$MYSQL_PASSWORD --silent; do
  echo "⏳ Waiting for MariaDB to be ready..."
  sleep 2
done

if [ ! -f /var/www/html/wp-config.php ]; then
  echo "→ wp-config.php を作成中..."

  wp config create \
    --dbname=$MYSQL_DATABASE \
    --dbuser=$MYSQL_USER \
    --dbpass=$MYSQL_PASSWORD \
    --dbhost=mariadb:3306 \
    --path=/var/www/html \
    --allow-root

  wp core install \
    --url=https://$DOMAIN_NAME \
    --title="$WP_TITLE" \
    --admin_user=$WP_ADMIN_USER \
    --admin_password=$WP_ADMIN_PASSWORD \
    --admin_email=$WP_ADMIN_EMAIL \
    --skip-email \
    --path=/var/www/html \
    --allow-root

  wp user create \
    $WP_USER \
    $WP_USER_EMAIL \
    --user_pass=$WP_USER_PASSWORD \
    --role=author \
    --path=/var/www/html \
    --allow-root

  echo "✔ WordPress 初期化完了"
else
  echo "✔ wp-config.php は既に存在しています"
fi
