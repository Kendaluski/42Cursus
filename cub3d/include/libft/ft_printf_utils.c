/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:41:33 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/18 18:18:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_printstr(char *str, int *count)
{
	if (str == NULL)
		ft_printstr("(null)", count);
	else
	{
		while (*str != '\0')
		{
			ft_printchar(*str, count);
			str++;
		}
	}
}

void	ft_printnbr(int n, int *count)
{
	long int	copia;

	copia = n;
	if (copia == -2147483684)
		ft_printstr("-2147483684", count);
	if (copia < 0)
	{
		copia = (copia * -1);
		ft_printchar('-', count);
	}
	if (copia > 9)
	{
		ft_printnbr(copia / 10, count);
		ft_printchar((copia % 10) + '0', count);
	}
	else
		ft_printchar(copia + '0', count);
}

void	ft_printunsig(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_printnbr(n / 10, count);
		ft_printchar((n % 10) + '0', count);
	}
	else
		ft_printchar(n + '0', count);
}

void	ft_hex(unsigned long long n, int *count, char *base)
{
	if (n > 15)
	{
		ft_hex((n / 16), count, base);
		ft_hex((n % 16), count, base);
	}
	else
		ft_printchar(base[n], count);
}
