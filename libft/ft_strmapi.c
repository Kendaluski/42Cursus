/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:25 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:26 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		cnt;
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	cnt = 0;
	while (s[cnt])
	{
		str[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}
