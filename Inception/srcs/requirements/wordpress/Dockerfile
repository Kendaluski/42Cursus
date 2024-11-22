FROM debian:bullseye

RUN apt update -y && \
    apt upgrade -y && \
    apt install php-fpm php-mysql curl -y

COPY ./files/wp_config.sh /wp_config.sh
RUN chmod +x /wp_config.sh
EXPOSE 9000

ENTRYPOINT ["/wp_config.sh"]