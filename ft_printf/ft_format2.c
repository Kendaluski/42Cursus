/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:36:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/05 15:44:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int num);
int	ft_digits(int num);

int	ft_count_hex(int num)
{
	int	cnt;

	cnt = 0;
	while (num != 0)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

int	ft_puthex(char c, int num)
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
	else if (num > 16)
	{
		ft_puthex(c, num / 16);
		ft_puthex(c, num % 16);
	}
	else
		write(1, &base[num], 1);
	return (num_dig);
}
int	ft_putptr(int ptr)
{
	int	num;

	write(1, "0x", 2);
	num = ft_puthex('x', ptr);
	return (num + 2);
}
int	ft_check_format(char c, int a)
{
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (c == 'c')
		return (ft_putchar(a));
	if (c == 'i')
		return (ft_putnbr(a));
	if (c == 'x' || c == 'X')
		return (ft_puthex(c, a));
	if (c == 'd')
		return (ft_putnbr(a));
	if (c == 'p')
		return (ft_putptr(a));
	return (0);
}
