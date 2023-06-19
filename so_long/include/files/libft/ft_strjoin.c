/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:32:59 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*newstr;
	unsigned int	cnt;
	unsigned int	cnt2;

	size = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(size * sizeof(char) + 1);
	if (!newstr)
		return (0);
	cnt = 0;
	cnt2 = 0;
	while (cnt < size)
	{
		if (cnt < size - ft_strlen(s2))
			newstr[cnt] = s1[cnt];
		else
		{
			newstr[cnt] = s2[cnt2];
			cnt2++;
		}
		cnt++;
	}
	newstr[cnt] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	printf("%s", ft_strjoin("lorem ipsum", "dolor sit amet"));
// }