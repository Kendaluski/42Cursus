# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:38:03 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/05/17 12:01:21 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FILES = *.c
OBJECTS = *.o
FLAGS = -Wall -Wextra -Werror

all :$(NAME)

$(NAME): $(OBJECTS)
	@ar rsc $(NAME) $(OBJECTS)

$(OBJECTS) :$(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS) $(NAME)

re :fclean all

.PHONY: all clean fclean re
