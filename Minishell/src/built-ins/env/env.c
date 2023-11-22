/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:26:31 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/01 19:13:33 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_print_matrix(char **matrix)
{
	int	cnt;

	cnt = 0;
	if (!matrix)
		return ;
	while (matrix[cnt])
	{
		printf("%s\n", matrix[cnt]);
		cnt++;
	}
	g_data.exit_status = 0;
}
