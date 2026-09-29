/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:14 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:16 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
