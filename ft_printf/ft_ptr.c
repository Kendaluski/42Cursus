/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:22:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/11 05:37:58 by jjaen-mo         ###   ########.fr       */
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
