# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:26:04 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/09/15 09:31:24 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
LIBFT = include/libft.a
FILES = $(shell find src -type f -name "*.c")
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C include

clean:
	@rm -f $(OBJS)
	@make -C include clean

fclean:
	@rm -f $(OBJS) $(NAME)
	@make -C include fclean

re: fclean all

.PHONY: all clean fclean re