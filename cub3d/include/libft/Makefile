# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:02:46 by jariza-o          #+#    #+#              #
#    Updated: 2023/09/17 19:43:48 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

SRC = 		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_atol.c ft_strcmp.c ft_putstr.c \
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
			ft_printf.c ft_printf_utils.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c \
			ft_free.c \

OBJT = 		$(SRC:.c=.o)

CFLAGS = 	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):
			@gcc -c $(CFLAGS) $(SRC)
			@ar rcs $(NAME) $(OBJT)

clean:
			@rm -f $(OBJT) $(OBJTBONUS)

fclean: 	clean
			@rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re