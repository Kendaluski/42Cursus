FROM debian:stable

RUN apt update -y && \
    apt upgrade -y && \
    apt install php-fpm php-mysql curl -y

COPY ./files/wp_config.sh /wp_config.sh
RUN chmod +x /wp_config.sh
EXPOSE 9000

ENTRYPOINT ["sleep", "10", "&&", "/wp_config.sh"]