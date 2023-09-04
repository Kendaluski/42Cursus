/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/17 12:12:23 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_chars(const char *str)
{
	int	cnt;
	int	chars;

	cnt = 0;
	chars = 0;
	while (str[cnt])
	{
		if (str[cnt] != '%' && str[cnt - 1] != '%')
			chars++;
		cnt++;
	}
	return (chars);
}

int	ft_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[cnt])
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
