#!/bin/bash
mkdir -p /var/www/html
cd /var/www/html
rm -rf *

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
chmod +x wp-cli.phar 
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
sed -i -r "s/database_name_here/$db_n/1" wp-config.php
sed -i -r "s/username_here/$db_u/1" wp-config.php
sed -i -r "s/password_here/$db_p/1" wp-config.php
sed -i -r "s/localhost/$db_h/1" wp-config.php


wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_AD_USER --admin_password=$WP_AD_PASS --admin_email=$WP_AD_EM --skip-email --allow-root
wp user create $WP_USER $WP_USR_EM --role=author --user_pass=$WP_PASS --allow-root

wp theme install twentysixteen --activate --allow-root

PHP_VERSION=$(php -r "echo PHP_MAJOR_VERSION.'.'.PHP_MINOR_VERSION;")
PHP_FPM_CONF="/etc/php/$PHP_VERSION/fpm/pool.d/www.conf"

if [ -f "$PHP_FPM_CONF" ]; then
    sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' "$PHP_FPM_CONF"
else
    echo "PHP-FPM configuration file not found: $PHP_FPM_CONF"
    exit 1
fi
mkdir -p /run/php
/usr/sbin/php-fpm7.3 -F