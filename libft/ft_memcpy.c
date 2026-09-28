/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:02:35 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:02:37 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int size)
{
	int			cnt;
	char		*str;
	const char	*str2;

	cnt = 0;
	str = dst;
	str2 = src;
	if (!str && !str2)
		return (0);
	while (cnt < size)
	{
		str[cnt] = str2[cnt];
		cnt++;
	}
	return (dst);
}
