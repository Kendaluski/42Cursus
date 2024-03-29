/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:58:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/15 09:07:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_a(int size, char **numbers, t_stack *stack_a)
{
	int		cnt;
	t_stack	*first;

	cnt = 1;
	if (size == 2)
		return (ft_init_a2(ft_split(numbers[1], ' '), stack_a));
	first = malloc(sizeof(t_stack));
	first->content = ft_atol(numbers[cnt]);
	first->act_pos = 0;
	first->next = malloc(sizeof(t_stack));
	stack_a = first->next;
	cnt++;
	while (cnt < size - 1)
	{
		stack_a->content = ft_atol(numbers[cnt]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		cnt++;
	}
	stack_a->content = ft_atol(numbers[cnt]);
	stack_a->next = NULL;
	return (first);
}

t_stacks	ft_ss(t_stacks stacks)
{
	stacks.stack_a = ft_sa(stacks.stack_a, 0);
	stacks.stack_b = ft_sa(stacks.stack_b, 0);
	ft_printf("ss\n");
	ft_set_position(&stacks.stack_a);
	ft_set_position(&stacks.stack_b);
	return (stacks);
}

t_stacks	ft_rr(t_stacks stacks)
{
	stacks.stack_a = ft_ra(stacks.stack_a, 0);
	stacks.stack_b = ft_rb(stacks.stack_b, 0);
	ft_printf("rr\n");
	ft_set_position(&stacks.stack_a);
	ft_set_position(&stacks.stack_b);
	return (stacks);
}

t_stacks	ft_rrr(t_stacks stacks)
{
	stacks.stack_a = ft_rra(stacks.stack_a, 0);
	stacks.stack_b = ft_rrb(stacks.stack_b, 0);
	ft_printf("rrr\n");
	ft_set_position(&stacks.stack_a);
	ft_set_position(&stacks.stack_b);
	return (stacks);
}

int	ft_get_size(t_stack *stack)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		cnt++;
		stack = stack->next;
	}
	return (cnt);
}
