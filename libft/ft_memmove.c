/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:02:30 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:02:30 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
