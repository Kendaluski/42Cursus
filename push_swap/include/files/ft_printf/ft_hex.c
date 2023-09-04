/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:36:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/11 05:38:16 by jjaen-mo         ###   ########.fr       */
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
