FROM debian:stable

RUN apt update -y
RUN apt upgrade -y
RUN apt install mariadb-server openrc -y
COPY ./files/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./files/mysql_conf.sh /
EXPOSE 3306

ENTRYPOINT ["sleep", "10", "&&", "/mysql_conf.sh"]