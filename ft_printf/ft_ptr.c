/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:48:16 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/29 21:53:30 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	num = ft_puthexp(ptr, 16);
	return (num + 2);
}
