# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 12:52:57 by jjaen-mo          #+#    #+#              #
#    Updated: 2024/04/30 13:00:56 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
FLAGS = -Wall -Wextra -Werror
MLX42 = include/MLX42/libmlx42.a
LIBFT = include/libft/libft.a

LIBS = -ldl -lglfw3 -pthread -lm $(MLX42)/libmlx42.a
SRCS = $(shell find src -iname "*.c")
# BONUS = $(shell find src_bonus -iname "*.c")
# BONUS_OBJS = $(BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# bonus: $(BONUS_OBJS) $(MLX42) $(LIBFT)
# 	@gcc $(FLAGS) $(BONUS_OBJS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

# src_bonus/%.o : src_bonus/%.c
# 	gcc $(FLAGS) -c $< -o $@

$(MLX42):
	make -C include/MLX42
$(LIBFT):
	make -C include/libft
	
clean:
	@rm -f $(OBJS)
	make -C include/MLX42 clean
	make -C include/libft clean

fclean:
	@rm -f $(OBJS) $(NAME) $(BONUS_OBJS)
	# make -C include/MLX42 fclean
	make -C include/libft fclean

re: fclean all

.PHONY: all clean fclean re bonus