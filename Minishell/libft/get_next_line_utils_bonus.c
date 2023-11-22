/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:17:05 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/18 18:17:46 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	c1;
	size_t	c2;
	size_t	strlen_s1;
	size_t	strlen_s2;

	if (!s1 && !s2)
		return (NULL);
	strlen_s1 = ft_strlen_gnl(s1);
	strlen_s2 = ft_strlen_gnl(s2);
	str = (char *)malloc(sizeof(char) * (strlen_s1 + strlen_s2 + 1));
	if (!str)
		return (0);
	c1 = 0;
	while (c1 < strlen_s1)
	{
		str[c1] = s1[c1];
		c1++;
	}
	c2 = 0;
	while (c2 < strlen_s2)
		str[c1++] = s2[c2++];
	str[c1] = '\0';
	free (s1);
	return (str);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (n != 0 && counter++ <= (n - 1))
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero_gnl(ptr, (count * size));
	return (ptr);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	if ((char)c == s[count])
		return ((char *)&s[count]);
	return (NULL);
}
