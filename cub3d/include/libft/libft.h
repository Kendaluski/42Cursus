/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:31:59 by jariza-o          #+#    #+#             */
/*   Updated: 2024/09/24 16:53:36 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

size_t		ft_strlen(const char *s);

void		*ft_memset(void *b, int c, size_t len);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

int			ft_toupper(int c);
int			ft_tolower(int c);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

char		*ft_strnstr(const char *haytack, const char *needle, size_t len);
int			ft_atoi(const char *str);

void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **list, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Ft_printf */
# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UPP_BASE "0123456789ABCDEF"

void		ft_printchar(char c, int *count);
void		ft_printstr(char *str, int *count);
void		ft_printnbr(int n, int *count);
void		ft_printunsig(unsigned int n, int *count);
void		ft_hex(unsigned long long n, int *count, char *base);

void		ft_control(va_list args, char *str, int *count);
int			ft_printf(char const *str, ...);

/* Get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_strlen_gnl(char *s);
char		*ft_strjoin_gnl(char *s1, char *s2);
void		ft_bzero_gnl(void *s, size_t n);
void		*ft_calloc_gnl(size_t count, size_t size);
char		*ft_strchr_gnl(char *s, int c);

char		*ft_readfile(int fd, char	*buf);
char		*ft_line(char *buf);
char		*ft_removeline(char *buf);
char		*get_next_line(int fd);

/* Functions Extra */
long int	ft_atol(const char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *s);

/* Free functions */
void		ft_free_doublepointer(char	**pointer);

#endif
