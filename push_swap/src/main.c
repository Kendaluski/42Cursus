/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/17 21:18:28 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_stack **stack)
{
	int		cnt;
	t_stack	*tmp;

	cnt = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = cnt;
		cnt++;
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc > 1)
	{
		stacks.stack_a = malloc(sizeof(t_stack));
		stacks.stack_b = malloc(sizeof(t_stack));
		if (!stacks.stack_b)
			return (0);
		stacks.stack_a = ft_init_a(argc, argv, stacks.stack_a);
		ft_set_position(&stacks.stack_a);
		stacks.sizea = argc - 1;
		if (stacks.sizea == 3)
			stacks.stack_a = ft_sort_three(stacks.stack_a);
		else
			stacks = ft_mid_point_sort(stacks);
		while (stacks.stack_a)
		{
			ft_printf("Content: %i Position: %i \n", stacks.stack_a->content,
					stacks.stack_a->pos);
			stacks.stack_a = stacks.stack_a->next;
		}
	}
}
