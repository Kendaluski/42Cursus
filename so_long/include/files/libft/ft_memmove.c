/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:06:08 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	cnt;
	char	*src;
	char	*dest;

	cnt = 0;
	dest = (char *)s1;
	src = (char *)s2;
	if (!s1 && !s2)
		return (s1);
	if (s1 > s2)
	{
		while (n--)
			dest[n] = src[n];
	}
	else
	{
		while (cnt < n)
		{
			dest[cnt] = src[cnt];
			cnt++;
		}
	}
	return (dest);
}
