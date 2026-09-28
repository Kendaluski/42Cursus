/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:01 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:03 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*str;

	if (!s1 || !set)
		return (0);
	if (s1[0] == '\0' && set[0] == '\0')
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_strchr(set, s1[size]))
		size--;
	str = ft_substr(s1, 0, (size_t)size + 1);
	return (str);
}
