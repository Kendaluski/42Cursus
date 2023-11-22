/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:03:11 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 20:42:20 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ctr_c(int signal);

void	ft_signals(void)
{
	signal(SIGINT, ctr_c);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	ctr_c(int signal)
{
	(void)signal;
	if (!g_data.line)
		ioctl(0, TIOCSTI, "\n");
	else
		write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
}
