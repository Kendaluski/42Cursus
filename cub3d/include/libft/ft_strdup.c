/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:17:07 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/05 12:18:29 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ss1;
	char	*d;
	size_t	c;

	ss1 = (char *)s1;
	d = (char *)malloc((ft_strlen(ss1) + 1));
	if (d == NULL)
		return (NULL);
	c = 0;
	while (ss1 && ss1[c] != '\0')
	{
		d[c] = ss1[c];
		c++;
	}
	d[c] = '\0';
	return (d);
}
