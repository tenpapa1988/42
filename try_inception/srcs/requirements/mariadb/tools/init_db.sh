#!/bin/bash

# Initialize MariaDB data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    # 初期化専用の一時起動（フォアグラウンド、バックグラウンドなし）
    echo "Performing initial setup..."
    
    # 初期化用の設定ファイルを作成
    cat > /tmp/init.sql << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF
    
    echo "Database initialization completed!"
fi

echo "Starting MariaDB..."

# フォアグラウンドで直接起動（初期化スクリプト付き）
if [ -f /tmp/init.sql ]; then
    exec mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/tmp/init.sql
else
    exec mysqld --user=mysql --datadir=/var/lib/mysql
fi