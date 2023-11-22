/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:42:26 by jariza-o          #+#    #+#             */
/*   Updated: 2022/10/12 13:29:49 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i++] != c && (s[i] == c || s[i] == '\0'))
			x++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	len;
	size_t	n;

	str = malloc(sizeof(char *) * (ft_wordcounter(s, c) + 1));
	if (!str)
		return (0);
	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				++len;
				++s;
			}
			str[n++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[n] = 0;
	return (str);
}
