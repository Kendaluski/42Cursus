/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/11 19:39:39 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stacks;

	if (argc > 1)
	{
		stacks.stack_a = malloc(sizeof(t_list));
		stacks.stack_b = malloc(sizeof(t_list));
		if (!stacks.stack_b)
			return (0);
		stacks.stack_a = ft_init_a(argc, argv, stacks.stack_a);
		if (argc == 4)
			stacks.stack_a = ft_sort_three(stacks.stack_a);
		else
			stacks = ft_sort(stacks);
		// while (stacks.stack_a)
		// {
		// 	ft_printf("%i\n", stacks.stack_a->content);
		// 	stacks.stack_a = stacks.stack_a->next;
		// }
	}
}
