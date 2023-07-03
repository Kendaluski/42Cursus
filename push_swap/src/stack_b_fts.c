/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:12:50 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/03 12:16:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_sb(t_list *stack_b)
{
    int tmp;
    
    if(!stack_b || !stack_b->next)
        return (stack_b);
    tmp = stack_b->content;
    stack_b->content = stack_b->next->content;
    stack_b->next->content = tmp;
    return (stack_b);
}

t_list *ft_pb(t_list *stack_b, t_list *stack_a)
{
    if(!stack_a)
        return (stack_b);
    stack_b->content = stack_a->content;
    return (stack_b);   
}

t_list *ft_rb(t_list *stack_b, int size)
{
    int tmp;
    int cnt;
    t_list *first;
    
    if(!stack_b || !stack_b->next)
        return (stack_b);
    first = stack_b;
    stack_b = stack_b->next;
    cnt = 0;
    while(cnt < size)
    {
        tmp = stack_b->content;
        stack_b->content = stack_b->next->content;
        stack_b->next->content = tmp;
        stack_b = stack_b->next;
        cnt++;
    }
    tmp = first->content;
    first->content = stack_b->content;
    stack_b->content = tmp;
    return (first);
}

t_list *ft_rrb(t_list *stack_b, int size)
{
    t_list *first;
    
    if(!stack_b || !stack_b->next)
        return (stack_b);
    first = ft_lstnlast(stack_b, size - 1);
    stack_b = stack_b->next;
    return (first);
}
