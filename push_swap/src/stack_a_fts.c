/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:41:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:38:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sa(t_list *stack_a)
{
	int	tmp;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	ft_set_position(&stack_a);
	ft_printf("sa\n");
	return (stack_a);
}

t_stack	ft_pa(t_stack stacks)
{
	t_list	*tmp;

	if (!stacks.stack_b)
		return (stacks);
	tmp = malloc(sizeof(t_list));
	tmp->content = stacks.stack_b->content;
	tmp->next = stacks.stack_a;
	if (stacks.stack_b->next)
		stacks.stack_b = stacks.stack_b->next;
	else
		stacks.stack_b = NULL;
	ft_printf("pa\n");
	stacks.stack_a = tmp;
	ft_set_position(&stacks.stack_a);
	return (stacks);
}

t_list	*ft_ra(t_list *stack_a)
{
	int		tmp;
	t_list	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
		stack_a = stack_a->next;
	}
	tmp = first->content;
	first->content = stack_a->content;
	stack_a->content = tmp;
	ft_set_position(&first);
	ft_printf("ra\n");
	return (first);
}

t_list	*ft_rra(t_list *stack_a)
{
	t_list	*last;
	t_list	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	last = stack_a->next;
	stack_a->next = NULL;
	last->next = first;
	ft_set_position(&last);
	ft_printf("rra\n");
	return (last);
}
