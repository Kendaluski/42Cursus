/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:38 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:39 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	srcsize;

	cnt = 0;
	srcsize = 0;
	if (dstsize > 0)
	{
		while (cnt < dstsize - 1 && src[cnt] != '\0')
		{
			dst[cnt] = src[cnt];
			cnt++;
		}
		dst[cnt] = '\0';
	}
	while (src[srcsize] != '\0')
		srcsize++;
	return (srcsize);
}
