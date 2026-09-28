/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:02:46 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:02:47 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cnt;
	const char	*str;

	str = s;
	cnt = 0;
	while (cnt < n)
	{
		if ((unsigned char)str[cnt] == (unsigned char)c)
			return ((void *)&str[cnt]);
		cnt++;
	}
	return (0);
}
