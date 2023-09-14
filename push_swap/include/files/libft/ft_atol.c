/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:56:23 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/14 20:09:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *c)
{
	long int	num;
	int			cnt;
	int			sign;

	sign = 1;
	num = 0;
	cnt = 0;
	while ((c[cnt] >= 9 && c[cnt] <= 13) || c[cnt] == 32)
		cnt++;
	if (c[cnt] == '-' || c[cnt] == '+')
	{
		if (c[cnt] == '-')
			sign = -1;
		cnt++;
	}
	while ((c[cnt] >= '0' && c[cnt] <= '9') && c[cnt] != '\0')
	{
		num = num * 10 + (c[cnt] - 48);
		cnt++;
	}
	return (num * sign);
}
