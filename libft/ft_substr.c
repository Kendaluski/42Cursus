/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:06:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:55:11 by jjaen-mo         ###   ########.fr       */
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
		substr[0] = '\0';
		return (substr);
	}
	if (len > (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s);
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
