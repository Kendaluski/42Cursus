/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:08:00 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/27 13:46:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	get_arr_num(const char *s, char c)
{
	int	cnt;
	int	arr_num;

	cnt = 0;
	arr_num = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] != c)
		{
			while (s[cnt] && s[cnt] != c)
				cnt++;
			arr_num++;
		}
		else
			cnt++;
	}
	return (arr_num);
}

static char	*get_arr(const char *s, char c)
{
	char	*arr;
	int		cnt;

	cnt = 0;
	while (s[cnt] != '\0' && s[cnt] != c)
		cnt++;
	arr = malloc((cnt + 1) * sizeof(char));
	if (!arr)
		return (0);
	cnt = 0;
	while (s[cnt] && s[cnt] != c)
	{
		arr[cnt] = s[cnt];
		cnt++;
	}
	arr[cnt] = '\0';
	return (arr);
}

static char	**free_mem(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		free(str[cnt]);
		cnt++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	int		num_arr;
	char	**arrr;

	num_arr = get_arr_num(s, c);
	arrr = malloc((num_arr + 1) * sizeof(char *));
	if (!arrr)
		return (0);
	cnt = 0;
	while (*s && cnt < num_arr)
	{
		while (*s && *s == c)
			s++;
		arrr[cnt] = get_arr(s, c);
		if (!arrr[cnt])
		{
			arrr = free_mem(arrr);
			return (0);
		}
		cnt++;
		while (*s != c && *s)
			s++;
	}
	arrr[cnt] = 0;
	return (arrr);
}

// int	main(void)
// {
// 	char **str;
// 	int cnt;
// 	cnt = 0;
// 	str = ft_split("hello!", ' ');
// 	while (str[cnt] != 0)
// 	{
// 		printf("%s\n", str[cnt]);
// 		cnt++;
// 	}
// }