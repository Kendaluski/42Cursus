/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:24 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/11 05:38:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list params, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(params, int)));
	if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(params, unsigned long int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(params, int)));
	if (c == 'u')
		return (ft_putud(va_arg(params, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(c, va_arg(params, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		cnt;
	int		chars;

	cnt = 0;
	chars = 0;
	va_start(lst, str);
	while (str[cnt])
	{
		if (str[cnt] != '%')
		{
			write(1, &str[cnt], 1);
			chars++;
		}
		else
		{
			chars = chars + ft_check_format(lst, str[cnt + 1]);
			cnt++;
		}
		cnt++;
	}
	va_end(lst);
	return (chars);
}
// int	main(void)
// {
// 	int a = ft_printf(" %u ", -1);
// 	ft_printf("\n%i\n", a);
// 	int b = printf(" %u ", -1);
// 	printf("\n%i\n", b);
// }