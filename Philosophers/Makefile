# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 19:16:23 by jjaen-mo          #+#    #+#              #
#    Updated: 2024/01/31 16:35:45 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -Werror
FILES = src/main.c src/utils.c src/mutexes.c src/philo.c src/clean.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME) -g

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re