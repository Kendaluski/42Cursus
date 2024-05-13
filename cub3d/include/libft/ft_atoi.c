/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:40:35 by jariza-o          #+#    #+#             */
/*   Updated: 2023/10/12 15:54:07 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	signo;
	int	buffer;

	count = 0;
	signo = 1;
	buffer = 0;
	while ((str[count] >= '\t' && str[count] <= '\r')
		|| str[count] == 32)
		count++;
	if (str[count] == 43 || str[count] == 45)
	{
		if (str[count] == 45)
			signo *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		buffer = (str[count] - '0') + (buffer * 10);
		count++;
	}
	return (signo * buffer);
}

/*
int main(void)
{
	printf("A");
}
*/