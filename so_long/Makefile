# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:21:06 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/05/31 13:55:05 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -fast
MLX42 = MLX42/libmlx42.a
LIBFT = include/libft.a

LIBS = -ldl -lglfw3 -pthread -lm $(MLX42)/libmlx42.a
SRCS = $(shell find src -iname "*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(LIBFT) $(MLX42)
	@gcc -Wall -Wextra -Werror $(SRCS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

$(MLX42):
	make -C MLX42
$(LIBFT):
	make -C include
	
clean:
	@rm -f $(OBJS)
	make -C MLX42 clean
	make -C include clean

fclean:
	@rm -f $(OBJS) $(NAME)
	make -C MLX42 fclean
	make -C include fclean

re: fclean all

.PHONY: all, clean, fclean, re