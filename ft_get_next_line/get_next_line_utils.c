/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:22:01 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/10/13 19:22:08 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strchr(char *str, char c)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
	{
		if (str[cnt] == c)
			return (&str[cnt]);
		cnt++;
	}
	return (0);
}

char	*ft_strjoin(char *buff, char *stack)
{
	char	*res;
	int		cnt;
	int		cnt2;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = '\0';
	}
	if (!stack || !buff)
		return (0);
	res = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(stack)) + 1);
	if (!res)
		return (0);
	cnt = -1;
	cnt2 = 0;
	if (stack)
		while (stack[++cnt] != '\0')
			res[cnt] = stack[cnt];
	while (buff[cnt2] != '\0')
		res[cnt++] = buff[cnt2++];
	res[cnt] = '\0';
	free(stack);
	return (res);
}
