/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:01 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/13 15:39:13 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_printf_matrix(char **str)
{
	int	i;

	i = 0;
	ft_printf("_________START PRINT MATRIX_________\n");
	ft_printf("%s\n", g_data.prompt);
	while (str && str[i])
	{
		ft_printf("%d      ", i);
		ft_printf("%s\n", str[i]);
		i++;
	}
	ft_printf("____________________________________\n");
}
