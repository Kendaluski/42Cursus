/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:47:56 by jariza-o          #+#    #+#             */
/*   Updated: 2022/10/10 12:01:45 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	c1;
	size_t	c2;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	c1 = 0;
	while (s1[c1] != '\0')
	{
		str[c1] = s1[c1];
		c1++;
	}
	c2 = 0;
	while (s2[c2] != '\0')
	{
		str[c1] = s2[c2];
		c1++;
		c2++;
	}
	str[c1] = '\0';
	return (str);
}
