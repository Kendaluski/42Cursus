/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:04:20 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:04:21 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	int	num;
	int	cnt;
	int	sign;

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
