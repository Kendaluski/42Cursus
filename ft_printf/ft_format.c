/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/03 17:41:55 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_countchars(const char *str)
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

int	ft_string(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	ft_char(char argl)
{
	write(1, &argl, 1);
	return (1);
}
static int	ft_digits(int num)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
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
int	ft_int(int num)
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
			ft_int(num / 10);
			ft_int(num % 10);
		}
		else
		{
			aux = num + 48;
			write(1, &aux, 1);
		}
	}
	return (count);
}
/*
int main (void)
{
	int a;

	a = ft_int(-2147483648);
	printf("\n%i", a);
}
*/