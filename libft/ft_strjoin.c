/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:47 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:48 by jojaen-m         ###   ########.fr       */
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
