/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:41:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/05 21:15:38 by jjaen-mo         ###   ########.fr       */
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
	return (stack_a);
}

t_list	*ft_pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	if (!stack_b)
		return (stack_a);
	tmp = malloc(sizeof(t_list));
	tmp->content = stack_b->content;
	tmp->next = stack_a;
	free(stack_b);
	return (tmp);
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
	return (last);
}
