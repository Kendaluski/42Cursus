/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:22:29 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/23 14:52:33 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief The size of the buffer that is used to read the file
 * 
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/**
 * @brief Get the next line of a file
 * 
 * @param fd File descriptor of the file to read
 * @return char* The line read
 */
char	*get_next_line(int fd);
/**
 * @brief Get the line from the stack passed by parameters
 * 
 * @param stack 
 * @return char* The line read from the stack
 */
char	*ft_get_line(char *stack);
/**
 * @brief Reads the file FD using BUFFER_SIZE, searches the next line inside 
 * the file and stores into STACK
 * 
 * @param stack Address of memmory where the line will be stored
 * @param fd File descriptor of the file to read
 * @return char* Returns the stack of memory with the next line or null if
 * there is no line. Also frees memory used if fails.
 */
char	*ft_read_file(char *stack, int fd);
/**
 * @brief Stores in STACK the remaining text in the file read
 * 
 * @param stack 
 * @return char* The STACK with the whole text remaining
 */
char	*ft_stack_refill(char *stack);
/**
 * @brief Joins two strings
 * 
 * @param buff First string 
 * @param stack Second string
 * @return char* The whole string resulting of joining both
 */
char	*ft_strjoin(char *buff, char *stack);
/**
 * @brief Searches for C character inside STR string
 * 
 * @param str The string where to search
 * @param c The character to search
 * @return char* The address where C is finded or null
 * if C is not inside STR
 */
char	*ft_strchr(char *str, char c);
/**
 * @brief Gets the lenght of the STR string
 * 
 * @param str The string to measure
 * @return int The lenght of the string
 */
int		ft_strlen(char *str);

#endif