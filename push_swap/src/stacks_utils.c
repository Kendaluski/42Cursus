/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:58:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:20:33 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init_a(int size, char **numbers, t_list *stack_a)
{
	int		cnt;
	t_list	*first;

	cnt = 1;
	first = malloc(sizeof(t_list));
	first->content = ft_atoi(numbers[cnt]);
	first->pos = 0;
	first->next = malloc(sizeof(t_list));
	stack_a = first->next;
	cnt++;
	while (cnt < size - 1)
	{
		stack_a->content = ft_atoi(numbers[cnt]);
		stack_a->next = malloc(sizeof(t_list));
		stack_a = stack_a->next;
		cnt++;
	}
	stack_a->content = ft_atoi(numbers[cnt]);
	stack_a->next = NULL;
	return (first);
}

t_stack	ft_ss(t_stack stacks)
{
	stacks.stack_a = ft_sa(stacks.stack_a);
	stacks.stack_b = ft_sa(stacks.stack_b);
	ft_printf("ss\n");
	return (stacks);
}

t_stack	ft_rr(t_stack stacks)
{
	stacks.stack_a = ft_ra(stacks.stack_a);
	stacks.stack_b = ft_rb(stacks.stack_b);
	ft_printf("rr\n");
	return (stacks);
}

t_stack	ft_rrr(t_stack stacks)
{
	stacks.stack_a = ft_rra(stacks.stack_a);
	stacks.stack_b = ft_rrb(stacks.stack_b);
	ft_printf("rrr\n");
	return (stacks);
}

int	ft_get_size(t_list *stack)
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
