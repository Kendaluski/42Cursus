/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:00:45 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:05:35 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	cnt;

	if (start >= (unsigned int)ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (0);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (0);
	cnt = 0;
	while (s[start] != '\0' && cnt < len)
	{
		substr[cnt] = s[start];
		cnt++;
		start++;
	}
	substr[cnt] = '\0';
	return (substr);
}
