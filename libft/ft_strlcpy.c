/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:00:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:17 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
