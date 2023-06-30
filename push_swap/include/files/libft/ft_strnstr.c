/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:29:18 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:54 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	cnt2;

	cnt = 0;
	if (needle[cnt] == '\0')
		return ((char *)haystack);
	while (haystack[cnt] != '\0')
	{
		cnt2 = 0;
		while (haystack[cnt + cnt2] == needle[cnt2] && cnt2 + cnt < len
			&& needle[cnt2] != '\0')
			cnt2++;
		if (needle[cnt2] == '\0')
			return ((char *)haystack + cnt);
		cnt++;
	}
	return (NULL);
}
