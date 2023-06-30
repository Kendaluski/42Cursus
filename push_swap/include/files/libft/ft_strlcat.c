/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:23:35 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/26 13:04:55 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	idst;
	unsigned int	isrc;
	unsigned int	srcsize;
	unsigned int	dstsize;

	idst = 0;
	isrc = 0;
	while (dst[idst] != '\0')
		idst++;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (size <= dstsize)
		return (srcsize + size);
	while (src[isrc] != '\0' && isrc < (size - dstsize - 1))
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = '\0';
	return (srcsize + dstsize);
}
// int main()
// {
//     char dest[11]="a";
//     printf("%i\n",ft_strlcat(dest,"lorem",15));
//     printf("%s\n",dest);
// }