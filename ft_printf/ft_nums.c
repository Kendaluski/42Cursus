/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:48:16 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/29 21:52:36 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(int num)
{
	unsigned int	digits;
	unsigned int	n;

	digits = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		digits++;
		n = -num;
	}
	else
		n = num;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	ft_putnbr(int num)
{
	int	aux;
	int	count;

	count = ft_count_digits(num);
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
