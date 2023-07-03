/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:41:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/03 12:24:41 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_sa(t_list *stack_a)
{
    int tmp;
    
    if(!stack_a || !stack_a->next)
        return (stack_a);
    tmp = stack_a->content;
    stack_a->content = stack_a->next->content;
    stack_a->next->content = tmp;
    return (stack_a);
}

t_list *ft_pa(t_list *stack_a, t_list *stack_b)
{
    if(!stack_b)
        return (stack_a);
    stack_a->content = stack_b->content;
    return (stack_a);   
}

t_list *ft_ra(t_list *stack_a, int size)
{
    int tmp;
    int cnt;
    t_list *first;
    
    if(!stack_a || !stack_a->next)
        return (stack_a);
    first = stack_a;
    stack_a = stack_a->next;
    cnt = 0;
    while(cnt < size)
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
        stack_a = stack_a->next;
        cnt++;
    }
    tmp = first->content;
    first->content = stack_a->content;
    stack_a->content = tmp;
    return (first);
}

t_list *ft_rra(t_list *stack_a, int size)
{
    t_list *first;
    
    if(!stack_a || !stack_a->next)
        return (stack_a);
    first = ft_lstnlast(stack_a, size - 1);
    stack_a = stack_a->next;
    return (first);
}
