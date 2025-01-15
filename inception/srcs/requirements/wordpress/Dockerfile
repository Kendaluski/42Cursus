FROM debian:bullseye

RUN apt update -y && \
    apt upgrade -y && \
    apt install php7.4-fpm php7.4-mysql curl -y

COPY ./files/wp_config.sh /wp_config.sh
COPY ./files/php-fpm.conf /etc/php/7.4/fpm/php-fpm.conf
COPY ./files/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN chmod +x /wp_config.sh
EXPOSE 9000

CMD ["/wp_config.sh"]