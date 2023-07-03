/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/03 12:30:03 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int cnt;

	if (argc > 1)
	{
		cnt = 0;
		stack_a = NULL;
		stack_b = NULL;
		stack_a = ft_init_a(argc, argv, stack_a);
		stack_b = ft_pa(stack_a, stack_b);
		ft_printf("%i\n", stack_b->next->content);
		while(cnt < argc - 1)
		{
			stack_b = stack_b->next;
			cnt++;
		}
	}
}
