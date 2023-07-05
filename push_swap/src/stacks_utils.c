/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:58:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/05 21:20:16 by jjaen-mo         ###   ########.fr       */
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

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	stack_a = ft_sa(stack_a);
	stack_b = ft_sa(stack_b);
}

void	ft_rr(t_list *stack_a, t_list *stack_b)
{
	stack_a = ft_ra(stack_a);
	stack_b = ft_rb(stack_b);
}

void	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	stack_a = ft_rra(stack_a);
	stack_b = ft_rrb(stack_b);
}
