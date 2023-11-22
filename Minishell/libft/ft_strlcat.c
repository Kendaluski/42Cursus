/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:25:51 by jariza-o          #+#    #+#             */
/*   Updated: 2022/10/04 01:20:39 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	scount;
	size_t	len_d;

	count = 0;
	scount = 0;
	len_d = ft_strlen(dst);
	if (len_d < (dstsize - 1) && dstsize > 0)
	{
		while (dst[count] != '\0')
			count++;
		while (src[scount] != '\0' && count < (dstsize - 1))
		{
			dst[count] = src[scount];
			count++;
			scount++;
		}
		dst[count] = '\0';
	}
	if (len_d >= dstsize)
		len_d = dstsize;
	return (len_d + ft_strlen(src));
}
