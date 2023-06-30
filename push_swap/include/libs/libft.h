/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:04:50 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/30 19:34:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//LibC Functions

/**
 * @brief Alphabetic int test
 * 
 * @param c 
 * @return int 1 if true 0 if false
 */
int					ft_isalpha(int c);
/**
 * @brief 0-9 int test
 * 
 * @param c 
 * @return int 1 if true 0 if false
 */
int					ft_isdigit(int c);
/**
 * @brief Alphanumeric int test
 * 
 * @param c 
 * @return int 1 if true 0 if false
 */
int					ft_isalnum(int c);
/**
 * @brief ASCII int test(0-127)
 * 
 * @param c 
 * @return int 1 if true 0 if false
 */
int					ft_isascii(int c);
/**
 * @brief Printable int test
 * 
 * @param c 
 * @return int 1 if true 0 if false
 */
int					ft_isprint(int c);
/**
 * @brief Returns length of a string
 * 
 * @param str 
 * @return int 
 */
int					ft_strlen(const char *str);
/**
 * @brief Sets N bytes of B string to C character
 * 
 * @param b 
 * @param c 
 * @param n 
 * @return void* string with changes
 */
void				*ft_memset(void *b, int c, int n);
/**
 * @brief Sets N bytes of STR string to 0
 * 
 * @param str 
 * @param n 
 */
void				ft_bzero(void *str, int n);
/**
 * @brief Copies SIZE bytes from SRC to DST with overlap
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return void* 
 */
void				*ft_memcpy(void *dst, const void *src, int size);
/**
 * @brief Copies N bytes from SRC to DST without overlap
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return void* 
 */
void				*ft_memmove(void *s1, const void *s2, size_t n);
/**
 * @brief Copies DSTSIZE - 1 characters from SRC to DST. Returns SRC size
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief Appends SRC string to the end of DST. Takes DST SIZE from 
 * parameters. Returns lenght of both strings
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return unsigned int 
 */
unsigned int		ft_strlcat(char *dst, char *src, unsigned int size);
/**
 * @brief Changes C to uppercase, only if possible
 * 
 * @param c 
 * @return int 
 */
int					ft_toupper(int c);
/**
 * @brief Changes C to lowercase, only if possible
 * 
 * @param c 
 * @return int 
 */
int					ft_tolower(int c);
/**
 * @brief Finds first occurrence of C inside STR and returns a PTR 
 * to that location
 * 
 * @param str 
 * @param c 
 * @return char* 
 */
char				*ft_strchr(const char *str, int c);
/**
 * @brief Finds last occurrence of C inside STR and returns a PTR 
 * to that location
 * 
 * @param str 
 * @param c 
 * @return char* 
 */
char				*ft_strrchr(const char *str, int c);
/**
 * @brief Compares 2 strings, returning + value if s1 > s2,
 * - if s2 > s1. Only compares N characters
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Changes a string to an integer
 * 
 * @param c 
 * @return int 
 */
int					ft_atoi(const char *c);
/**
 * @brief Locates the first occurrence of C (converted to UNSIGNED CHAR) 
 * in S string, returning a PTR to that value
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void				*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Compares 2 strings until N bytes. If different, return the 
 * difference
 * 
 * @param str1 
 * @param str2 
 * @param n 
 * @return int 
 */
int					ft_memcmp(const void *str1, const void *str2, size_t n);
/**
 * @brief Finds NEEDLE inside LEN characters of HAYSTACK. 
 * Returns a PTR to first occurrence of NEEDLE in HAYSTACK
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
/**
 * @brief Allocate enough space for COUNT objects that are SIZE size of bytes. 
 * It is filled with 0s and returns a PTR to first value
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void				*ft_calloc(size_t count, size_t size);
/**
 * @brief Save a copy of S1, allocating memory and returning PTR to first value
 * 
 * @param s1 
 * @return char* 
 */
char				*ft_strdup(const char *s1);

//Additional Functions

/**
 * @brief Allocates memory and creates substring of S. 
 * It begins in START and has LEN length
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Allocates and creates the concatenation between s1 and s2
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char				*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Deletes SET characters inside S string, from end and start
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char				*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Splits S into an array of strings, divided by C character
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char				**ft_split(char const *s, char c);
/**
 * @brief Changes N integer to an string, minding of negatives
 * 
 * @param n 
 * @return char* 
 */
char				*ft_itoa(int n);

/**
 * @brief To every char of S applies F function and stores in another string 
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief To every char of S applies F function, recieving index and 
 * memory location of S position.
 * 
 * @param s 
 * @param f 
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * @brief Writes a char C into FD file
 * 
 * @param c 
 * @param fd 
 */
void				ft_putchar_fd(char c, int fd);
/**
 * @brief Writes a string S into FD file
 * 
 * @param s 
 * @param fd 
 */
void				ft_putstr_fd(char *s, int fd);
/**
 * @brief Writes a string S into FD file and adds a "\n"
 * 
 * @param s 
 * @param fd 
 */
void				ft_putendl_fd(char *s, int fd);
/**
 * @brief Writes a number N into FD file
 * 
 * @param n 
 * @param fd 
 */
void				ft_putnbr_fd(int n, int fd);

//Bonus Part

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Creates a node, using malloc. Content will start 
 * with content and next with NULL
 * 
 * @param content 
 * @return t_list* 
 */
t_list				*ft_lstnew(void *content);
/**
 * @brief Adds the node NEW at the beginning of LST list
 * 
 * @param lst 
 * @param new 
 */
void				ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Counts the number of nodes in LST list
 * 
 * @param lst 
 * @return int 
 */
int					ft_lstsize(t_list *lst);
/**
 * @brief Returns the last node of LST list
 * 
 * @param lst 
 * @return t_list* the last node of LST
 */
t_list				*ft_lstlast(t_list *lst);
/**
 * @brief Adds node NEW at the end of LST list
 * 
 * @param lst 
 * @param new 
 */
void				ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Frees the memmory of LST node and deletes
 * the node content using DEL function
 * 
 * @param lst 
 * @param del 
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes and frees the LST node and every node untill the
 * end of the list, using free and DEL. The last node must be NULL
 * 
 * @param lst 
 * @param del 
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Applies F function to the content of every node of 
 * LST list
 * 
 * @param lst 
 * @param f 
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Applies F function to the content of every node of LST
 * list. Creates a new list as a result of that recursion.
 * DEL is used in case you need to delete a node.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//PRINTF
int					ft_printf(char const *str, ...);
//GET NEXT LINE
char				*get_next_line(int fd);

#endif