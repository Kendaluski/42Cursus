/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:51:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/09 16:43:53 by jjaen-mo         ###   ########.fr       */
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
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_digits(int num);
int	ft_putnbr(int num);
int	ft_countchars(const char *str);
int	ft_count_hex(long unsigned int num);
int	ft_puthex(char c, unsigned int num);
int	ft_putptr(long unsigned int ptr);
int	ft_puthexp(long unsigned int ptr, int num);
int	ft_check_format(char c, int a);
int	ft_digitsu(unsigned int num);
int	ft_putud(unsigned int num);

#endif