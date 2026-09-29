/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:20:00 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/29 20:47:56 by jojaen-m         ###   ########.fr       */
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
