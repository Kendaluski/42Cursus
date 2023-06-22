/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:49:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/26 14:45:33 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);

static int	num_digits(unsigned int n)
{
	unsigned int	digits;

	digits = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 9)
	{
		n = n / 10;
		digits++;
	}
	if (n > 0)
		digits++;
	return (digits);
}

static int	get_div(unsigned int num)
{
	int				tens;
	unsigned int	cnt;

	tens = 1;
	cnt = 0;
	while (cnt < num - 1)
	{
		tens = tens * 10;
		cnt++;
	}
	return (tens);
}

static char	*str_prep(int dig, char *str, int cnt, unsigned int n)
{
	unsigned int	div;
	unsigned int	mod;

	while (dig > 0)
	{
		div = get_div(dig);
		mod = div;
		str[cnt] = (n / div) + 48;
		n = n % mod;
		dig--;
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}

static char	*neg_case_zero(unsigned int n2)
{
	char	*str;

	if (n2 == 0)
	{
		str = malloc(2);
		if (!str)
			return (0);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(num_digits(n2) * sizeof(char) + 2);
	if (!str)
		return (0);
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	cnt;
	unsigned int	n2;

	cnt = 0;
	if (n < 0 || n == 0)
	{
		n2 = (unsigned int)n * -1;
		str = neg_case_zero(n2);
		cnt = 1;
	}
	else
	{
		n2 = (unsigned int)n;
		str = malloc(num_digits(n2) * sizeof(char) + 1);
	}
	if (!str)
		return (0);
	str = str_prep(num_digits(n2), str, cnt, n2);
	return (str);
}
