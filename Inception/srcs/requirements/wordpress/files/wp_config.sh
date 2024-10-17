#!/bin/bash
mkdir -p /var/www/html
cd /var/www/html
rm -rf *

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
chmod +x wp-cli.phar 
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root

mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
sed -i -r "s/db1/$dbw_n/1"   wp-config.php
sed -i -r "s/user/$dbw_u/1"  wp-config.php
sed -i -r "s/pwd/$dbw_p/1"    wp-config.php

wp core install --url=$DOMAIN_NAME/ --title=$WP_TITLE --admin_user=$WP_AD_USER --admin_password=$WP_AD_PASS --admin_email=$WP_AD_EM --skip-email --allow-root
wp user create $WP_USER $WP_USR_EM --role=author --user_pass=$WP_PASS --allow-root

wp theme install twentysixteen --activate --allow-root
sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf
mkdir /run/php
/usr/sbin/php-fpm7.3 -F