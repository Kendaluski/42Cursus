/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:40:58 by jariza-o          #+#    #+#             */
/*   Updated: 2022/11/17 17:40:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_control(va_list args, char *str, int *count)
{
	if (*str == 'c')
		ft_printchar(va_arg(args, int), count);
	else if (*str == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (*str == 'p')
	{
		ft_printstr("0x", count);
		ft_hex(va_arg(args, unsigned long long), count, HEX_LOW_BASE);
	}
	else if (*str == 'd' || *str == 'i')
		ft_printnbr(va_arg(args, int), count);
	else if (*str == 'u')
		ft_printunsig(va_arg(args, unsigned int), count);
	else if (*str == 'x')
		ft_hex(va_arg(args, unsigned int), count, HEX_LOW_BASE);
	else if (*str == 'X')
		ft_hex(va_arg(args, unsigned int), count, HEX_UPP_BASE);
	else if (*str == '%')
		ft_printchar('%', count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_control(args, (char *)str, &count);
		}
		else
		{
			ft_printchar(*str, &count);
		}
		str++;
	}
	va_end(args);
	return (count);
}
