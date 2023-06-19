# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:21:06 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/06/02 18:16:48 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLX42 = MLX42/libmlx42.a
LIBFT = include/libft.a

LIBS = -ldl -lglfw3 -pthread -lm $(MLX42)/libmlx42.a
SRCS = $(shell find src -iname "*.c")
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

$(OBJS): $(SRCS)
	@mkdir -p src
	@gcc -c $(SRCS) $(FLAGS)
	@mv *.o src

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