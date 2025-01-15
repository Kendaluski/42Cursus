#!/bin/bash
mkdir -p /var/www/html
cd /var/www/html
rm -rf *

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
chmod +x wp-cli.phar 
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root --path=/var/www/html/

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
sed -i -r "s/database_name_here/$db_n/1" wp-config.php
sed -i -r "s/username_here/$db_u/1" wp-config.php
sed -i -r "s/password_here/$db_p/1" wp-config.php
sed -i -r "s/localhost/$db_h/1" wp-config.php

echo "define('WP_HOME', 'https://$DOMAIN_NAME');" >> wp-config.php
echo "define('WP_SITEURL', 'https://$DOMAIN_NAME');" >> wp-config.php

wp core install --path=/var/www/html --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_AD_USER --admin_password=$WP_AD_PASS --admin_email=$WP_AD_EM --skip-email --allow-root
wp user create $WP_USER $WP_USR_EM --role=author --user_pass=$WP_PASS --allow-root --path=/var/www/html

wp theme install twentysixteen --activate --allow-root

PHP_VERSION=$(php -r "echo PHP_MAJOR_VERSION.'.'.PHP_MINOR_VERSION;")
PHP_FPM_CONF="/etc/php/$PHP_VERSION/fpm/pool.d/www.conf"

sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 0.0.0.0:9000/g' "$PHP_FPM_CONF"
chown -R www-data:www-data /var/www/html && chmod -R 775 /var/www/html
mkdir -p /run/php
php-fpm7.4 -y /etc/php/7.4/fpm/php-fpm.conf -F