all : up

up : 
	docker-compose -f ./srcs/docker-compose.yml up -d

down : 
	@docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@docker-compose -f ./srcs/docker-compose.yml start

prune:
	@sudo docker system prune --all --force --volumes

re: stop down prune up

status : 
	@sudo docker ps