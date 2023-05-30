/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:51:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/17 12:02:28 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

/**
 * @brief Is the main function. It works as printf function
 * 
 * @param str 
 * @param ... 
 * @return int Number of characters printed
 */
int	ft_printf(char const *str, ...);
/**
 * @brief Counts the number of chars in str param of printf
 * 
 * @param str 
 * @return int Number of characters
 */
int	ft_count_chars(const char *str);
/**
 * @brief Check what format is passed to print
 * 
 * @param params 
 * @param c 
 * @return int Number of chars printed via that format
 */
int	ft_check_format(va_list params, char c);
/**
 * @brief Prints the C character
 * 
 * @param c 
 * @return int Number of characters printed
 */
int	ft_putchar(char c);
/**
 * @brief Prints the string STR
 * 
 * @param str 
 * @return int Number of characters printed
 */
int	ft_putstr(char *str);
/**
 * @brief Prints the addres of memory pointed by
 * PTR in hexadecimal base
 * 
 * @param ptr 
 * @return int Number of chars printed
 */
int	ft_putptr(long unsigned int ptr);
/**
 * @brief Prints the address in hexadecimal
 * 
 * @param ptr 
 * @param num 
 * @return int Number of chars printed
 */
int	ft_puthexp(long unsigned int ptr, int num);
/**
 * @brief Counts the digits of a hexadecimal number
 * 
 * @param num 
 * @return int Number of digits
 */
int	ft_count_hex(long unsigned int num);
/**
 * @brief Prints the number NUM
 * 
 * @param num 
 * @return int Number of digits printed
 */
int	ft_putnbr(int num);
/**
 * @brief Counts the number of digits of NUM
 * 
 * @param num 
 * @return int The number of digits
 */
int	ft_count_digits(int num);
/**
 * @brief Counts the digits of an unsigned decimal
 * 
 * @param num 
 * @return int The number of digits
 */
int	ft_digitsu(unsigned int num);
/**
 * @brief Prints the unsigned decimal NUM
 * 
 * @param num 
 * @return int The number of digits printed
 */
int	ft_putud(unsigned int num);
/**
 * @brief Prints a number in hexadecimal base
 * 
 * @param c 
 * @param num 
 * @return int The number of digits printed
 */
int	ft_puthex(char c, unsigned int num);

#endif