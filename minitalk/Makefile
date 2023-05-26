# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 18:10:56 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/05/26 19:27:40 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = src/client/main.c
SFILE = src/server/main.c
COBJ = src/client/main.o
SOBJ = src/server/main.o
CFILEB = src/client/main_bonus.c
SFILEB = src/server/main_bonus.c
COFILEB = src/client/main_bonus.o
SOFILEB = src/server/main_bonus.o
FLAGS = -Wall -Werror -Wextra

all: client server

bonus: clientb serverb

cliento: $(CFILE)
	@gcc -c $(CFILE) $(FLAGS)
servero: $(SFILE)
	@gcc -c $(SFILE) $(FLAGS)

client: $(COBJ)
	@gcc $(COBJ) $(FLAGS) -o client
server: $(SOBJ)
	@gcc $(SOBJ) $(FLAGS) -o server 

clientob: $(CFILEB)
	@gcc -c $(CFILEB) $(FLAGS)
serverob: $(SFILEB)
	@gcc -c $(SFILEB) $(FLAGS)

clientb: $(COFILEB)
	@gcc $(COFILEB) $(FLAGS) -o client
serverb: $(SOFILEB)
	@gcc $(SOFILEB) $(FLAGS) -o server 

clean:
	@rm -f $(COBJ) $(SOBJ) $(COFILEB) $(SOFILEB)
fclean: clean
	@rm -f server client

re: fclean all
.PHONY: re clean fclean all bonus