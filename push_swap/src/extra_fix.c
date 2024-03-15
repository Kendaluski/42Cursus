/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 00:14:44 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/16 00:15:25 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_lower(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*lower;

	tmp = stack_a;
	lower = tmp;
	while (tmp)
	{
		if (tmp->content < lower->content)
			lower = tmp;
		tmp = tmp->next;
	}
	return (lower);
}

t_stacks	ft_final_sort(t_stacks stacks)
{
	ft_set_position(&stacks.stack_a);
	stacks.sizea = ft_get_size(stacks.stack_a);
	stacks.lower = ft_get_lower(stacks.stack_a);
	if (stacks.lower->act_pos > stacks.sizea / 2)
	{
		while (!ft_is_sort(stacks.stack_a))
			stacks.stack_a = ft_rra(stacks.stack_a, 1);
	}
	else
	{
		while (!ft_is_sort(stacks.stack_a))
			stacks.stack_a = ft_ra(stacks.stack_a, 1);
	}
	return (stacks);
}
