/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:12:50 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/06 18:50:36 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sb(t_list *stack_b)
{
	int	tmp;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	ft_printf("sb\n");
	return (stack_b);
}

void ft_pb(t_list *stack_b, t_list *stack_a)
{
	t_list	*tmp;

	if (stack_a)
	{
		tmp = malloc(sizeof(t_list));
		tmp->content = stack_a->content;
		tmp->next = stack_b;
		if(stack_a->next)
			stack_a = stack_a->next;
		else
			stack_a = NULL;
		ft_printf("%i\n", stack_a->content);
		ft_printf("pb\n");
	}
}

t_list	*ft_rb(t_list *stack_b)
{
	int		tmp;
	t_list	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	stack_b = stack_b->next;
	while (stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
		stack_b = stack_b->next;
	}
	tmp = first->content;
	first->content = stack_b->content;
	stack_b->content = tmp;
	ft_printf("rb\n");
	return (first);
}

t_list	*ft_rrb(t_list *stack_b)
{
	t_list	*last;
	t_list	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	last = stack_b->next;
	stack_b->next = NULL;
	last->next = first;
	ft_printf("rrb\n");
	return (last);
}
