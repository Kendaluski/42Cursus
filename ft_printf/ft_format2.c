/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:36:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/09 18:49:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hex(long unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

int	ft_puthex(char c, unsigned int num)
{
	char	*base;
	int		num_dig;

	num_dig = ft_count_hex(num);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	if (num == 0)
		write(1, &base[0], 1);
	else if (num >= 16)
	{
		ft_puthex(c, num / 16);
		ft_puthex(c, num % 16);
	}
	else
		write(1, &base[num], 1);
	return (num_dig);
}

int	ft_puthexp(long unsigned int ptr, int num)
{
	char	*base;

	base = "0123456789abcdef";
	if (num > 0)
	{
		if (ptr > 15)
			ft_puthexp(ptr / 16, num - 1);
		write(1, &base[ptr % 16], 1);
	}
	return (ft_count_hex(ptr));
}

int	ft_putptr(long unsigned int ptr)
{
	int	num;

	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	num = ft_puthexp(ptr, 16);
	return (num + 2);
}

int	ft_format_number(char c, unsigned int a)
{
	if(c == 'u')
		return(ft_putud(a));
	if(c == 'x')
		return(ft_puthex(c,a));
	return (0);
}
int	ft_digitsu(unsigned int num)
{
	int	n;
	int	cnt;

	cnt = 0;
	n = num;
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}
int	ft_putud(unsigned int num)
{
	int aux;
	int count;

	count = ft_digitsu(num);
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
	return (count);
}