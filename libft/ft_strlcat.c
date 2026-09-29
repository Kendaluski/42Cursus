/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:42 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:43 by jojaen-m         ###   ########.fr       */
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
