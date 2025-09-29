# #!/bin/bash

# # Initialize MariaDB data directory if it doesn't exist
# if [ ! -d "/var/lib/mysql/mysql" ]; then
#     echo "Initializing MariaDB data directory..."
#     mysql_install_db --user=mysql --datadir=/var/lib/mysql
# fi

# # Start MariaDB
# echo "Starting MariaDB..."
# mysqld --user=mysql --datadir=/var/lib/mysql &

# # Wait for MariaDB to be ready
# echo "Waiting for MariaDB to be ready..."
# while ! mysqladmin ping -h"localhost" --silent; do
#     sleep 2
# done

# echo "MariaDB is ready!"

# # Create database and user if they don't exist
# mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
# mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
# mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
# mysql -e "FLUSH PRIVILEGES;"

# echo "Database setup completed!"

# # Keep MariaDB running
# wait 


#!/bin/bash

set -e
set -x  # デバッグ出力を有効化

echo "=== MariaDB Container Startup Debug ==="
echo "PWD: $(pwd)"
echo "USER: $(whoami)"
echo "Environment variables:"
env | grep MYSQL || true

# データディレクトリの状態確認
echo "=== Checking data directory ==="
ls -la /var/lib/mysql/ || echo "Directory doesn't exist or not accessible"

# 権限確認
echo "=== Checking permissions ==="
chown -R mysql:mysql /var/lib/mysql
chmod 755 /var/lib/mysql

# Initialize MariaDB data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "=== Initializing MariaDB data directory ==="
    mysql_install_db --user=mysql --datadir=/var/lib/mysql --auth-root-authentication-method=normal
    echo "=== Data directory initialized ==="
else
    echo "=== Data directory already exists ==="
fi

echo "=== Starting MariaDB (no background processes) ==="

# シンプルに起動（初期化は後で手動実行）
exec mysqld --user=mysql \
    --datadir=/var/lib/mysql \
    --bind-address=0.0.0.0 \
    --port=3306 \
    --skip-networking=false