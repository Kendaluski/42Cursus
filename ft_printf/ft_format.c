/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:42 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/03 15:56:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_string(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
	return (cnt);
}

int	ft_char(char argl)
{
	write(1, &argl, 1);
	return (1);
}

// int ft_int(int num)
// {
// 		int	aux;
// 		int i;

// 	i = 0;
// 	if (n == -2147483648)
// 		write(1, "-2147483648", 11);
// 	else if (n == 2147483647)
// 		write(1, "2147483647", 10);
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			n = n * -1;
// 			write(1, "-", 1);
// 		}
// 		if (n > 9)
// 		{
// 			ft_putnbr_fd(n / 10, 1);
// 			ft_putnbr_fd(n % 10, 1);

// 		}
// 		else
// 		{
// 			aux = n + 48;
// 			write(1, &aux, 1);
// 		}
// 	}
// }