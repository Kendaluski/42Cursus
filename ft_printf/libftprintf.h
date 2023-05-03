/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:51:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/28 17:08:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
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

#endif