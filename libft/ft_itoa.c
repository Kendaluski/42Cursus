/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:49:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/25 14:56:29 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);

static int	num_digits(int n)
{
	int	digits;

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

static int	get_div(int num)
{
	int	tens;
	int	cnt;

	tens = 1;
	cnt = 0;
	while (cnt < num - 1)
	{
		tens = tens * 10;
		cnt++;
	}
	return (tens);
}

static char	*str_prep(int dig, char *str, int cnt, int n)
{
	int	div;
	int	mod;

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

static char	*case_z(int n)
{
	int		cnt;
	char	*str;

	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (0);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		cnt = 0;
		str = ft_itoa(n + 1);
		while (str[cnt])
		{
			if (str[cnt + 1] == '\0')
				str[cnt] = str[cnt] + 1;
			cnt++;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		cnt;

	cnt = 0;
	if (n == 0 || n == -2147483648)
		str = case_z(n);
	else
	{
		if (n < 0)
		{
			str = malloc(num_digits(n) * sizeof(char) + 2);
			if (!str)
				return (0);
			str[0] = '-';
			n = n * -1;
			cnt = 1;
		}
		else
			str = malloc(num_digits(n) * sizeof(char) + 1);
		if (!str)
			return (0);
		str = str_prep(num_digits(n), str, cnt, n);
	}
	return (str);
}
