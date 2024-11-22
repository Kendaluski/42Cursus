FROM debian:bullseye

ARG db_n
ARG db_u
ARG db_p

RUN apt-get update -y && apt-get upgrade -y && apt-get install mariadb-server -y

EXPOSE 3306

COPY ./files/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN mkdir -p /var/run/mysqld
RUN chown -R mysql:mysql /var/run/mysqld

RUN service mariadb start && \
    echo "CREATE DATABASE IF NOT EXISTS ${db_n} ;" > init.sql && \
    echo "CREATE USER IF NOT EXISTS '${db_u}'@'%' IDENTIFIED BY '${db_p}' ;" >> init.sql && \
    echo "GRANT ALL PRIVILEGES ON ${db_n}.* TO '${db_u}'@'%' ;" >> init.sql && \
    echo "FLUSH PRIVILEGES;" >> init.sql && \
    mariadb < init.sql

CMD ["mysqld"]