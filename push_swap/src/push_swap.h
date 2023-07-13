/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:19:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:28:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libs/libft.h"

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
}			t_stack;

t_list		*ft_init_a(int size, char **numbers, t_list *stack_a);
void		ft_set_position(t_list **stack);
t_list		*ft_sa(t_list *stack_a);
t_stack		ft_pa(t_stack stacks);
t_list		*ft_ra(t_list *stack_a);
t_list		*ft_rra(t_list *stack_a);
t_list		*ft_sb(t_list *stack_a);
t_stack		ft_pb(t_stack stacks);
t_list		*ft_rb(t_list *stack_a);
t_list		*ft_rrb(t_list *stack_a);
t_stack		ft_ss(t_stack stacks);
t_stack		ft_rr(t_stack stacks);
t_stack		ft_rrr(t_stack stacks);
t_list		*ft_sort_three(t_list *stack_a);
t_stack		ft_sort(t_stack stacks);
int			ft_get_size(t_list *stack);

#endif