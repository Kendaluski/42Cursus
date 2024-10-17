FROM debian:stable

#INSTALL
RUN apt update -y
RUN apt install nginx -y
RUN apt install openssl -y

#SSL
EXPOSE 443
RUN mkdir /etc/nginx/ssl
RUN chmod 700 /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=ES/L=MA/O=7777/OU=student/CN=jjaen-mo.42.fr"
COPY files/default /etc/nginx/sites-available/default

CMD [ "nginx", "-g", "daemon off;" ]