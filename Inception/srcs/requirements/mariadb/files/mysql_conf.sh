#!/bin/bash

rc-service mariadb restart

echo "CREATE DATABASE IF NOT EXISTS $db_n ;" > init.sql
echo "CREATE USER IF NOT EXISTS '$db_u'@'%' ITENFIFIED BY '$db_p' ;" >> init.sql
echo "GRANT ALL PRIVILEGES ON $db_n.* TO '$db_u'@'%' ;" >> init.sql
echo "FLUSH PRIVILEGES ;" >> init.sql

mysql < init.sql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld