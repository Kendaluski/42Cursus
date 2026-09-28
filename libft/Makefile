# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 18:01:05 by jojaen-m          #+#    #+#              #
#    Updated: 2026/09/28 10:18:34 by jojaen-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c


OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all :$(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re