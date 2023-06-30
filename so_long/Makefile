# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 17:21:06 by jjaen-mo          #+#    #+#              #
#    Updated: 2023/06/30 14:44:44 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLX42 = MLX42/libmlx42.a
LIBFT = include/libft.a

LIBS = -ldl -lglfw3 -pthread -lm $(MLX42)/libmlx42.a
SRCS = $(shell find src -iname "*.c")
BONUS = $(shell find src_bonus -iname "*.c")
BONUS_OBJS = $(BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS_OBJS) $(MLX42) $(LIBFT)
	@gcc $(FLAGS) $(BONUS_OBJS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	@gcc $(FLAGS) $(OBJS) $(MLX42) $(LIBFT) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/jjaen-mo/.brew/opt/glfw/lib/" -o $(NAME)

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

src_bonus/%.o : src_bonus/%.c
	gcc $(FLAGS) -c $< -o $@

$(MLX42):
	make -C MLX42
$(LIBFT):
	make -C include
	
clean:
	@rm -f $(OBJS)
	make -C MLX42 clean
	make -C include clean

fclean:
	@rm -f $(OBJS) $(NAME) $(BONUS_OBJS)
	make -C MLX42 fclean
	make -C include fclean

re: fclean all

.PHONY: all clean fclean re bonus