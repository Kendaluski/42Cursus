/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/09 18:57:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countchars(const char* str)
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

int	ft_digits(int num)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i++;
		n = -num;
	}
	else
		n = num;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int num)
{
	int	aux;
	int	count;

	count = ft_digits(num);
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			num = num * -1;
			write(1, "-", 1);
		}
		if (num > 9)
		{
			ft_putnbr(num / 10);
			ft_putnbr(num % 10);
		}
		else
		{
			aux = num + 48;
			write(1, &aux, 1);
		}
	}
	return (count);
}
