/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:19:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/17 15:33:07 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libs/libft.h"

typedef struct s_stack
{
	int				content;
	int				pos;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				*mids;
	int				sizea;
	int				sizeb;
}					t_stacks;

t_stack				*ft_init_a(int size, char **numbers, t_stack *stack_a);
void				ft_set_position(t_stack **stack);
t_stack				*ft_sa(t_stack *stack_a);
t_stacks			ft_pa(t_stacks stacks);
t_stack				*ft_ra(t_stack *stack_a);
t_stack				*ft_rra(t_stack *stack_a);
t_stack				*ft_sb(t_stack *stack_a);
t_stacks			ft_pb(t_stacks stacks);
t_stack				*ft_rb(t_stack *stack_a);
t_stack				*ft_rrb(t_stack *stack_a);
t_stacks			ft_ss(t_stacks stacks);
t_stacks			ft_rr(t_stacks stacks);
t_stacks			ft_rrr(t_stacks stacks);
t_stack				*ft_sort_three(t_stack *stack_a);
t_stacks			ft_sort(t_stacks stacks);
t_stacks			ft_mid_point_sort(t_stacks stacks);
int					ft_get_size(t_stack *stack);
int					ft_get_min(t_stack *stack);

#endif