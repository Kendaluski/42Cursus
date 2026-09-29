/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:48:16 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/29 21:51:59 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digitsu(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		cnt++;
	}
	return (cnt);
}

int	ft_putud(unsigned int num)
{
	int	aux;
	int	count;

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
