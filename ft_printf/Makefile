# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 20:48:16 by jojaen-m          #+#    #+#              #
#    Updated: 2026/09/29 21:53:46 by jojaen-m         ###   ########.fr        #
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
	@cc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS) $(NAME)

re :fclean all

.PHONY: all clean fclean re
