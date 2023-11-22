/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:32:39 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 16:59:32 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_len_change_env(int *len_env)
{
	char	*str;

	str = ft_itoa(g_data.exit_status);
	*len_env = ft_strlen(str);
	free (str);
}
