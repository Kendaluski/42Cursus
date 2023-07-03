/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:19:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/03 12:25:43 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libs/libft.h"

t_list  *ft_init_a(int size, char **numbers, t_list *stack_a);
t_list  *ft_lstnlast(t_list *lst, int size);
t_list  *ft_sa(t_list *stack_a);
t_list  *ft_pa(t_list *stack_a, t_list *stack_b);
t_list  *ft_ra(t_list *stack_a, int size);
t_list  *ft_rra(t_list *stack_a, int size);
t_list  *ft_sb(t_list *stack_a);
t_list  *ft_pb(t_list *stack_a, t_list *stack_b);
t_list  *ft_rb(t_list *stack_a, int size);
t_list  *ft_rrb(t_list *stack_a, int size);
void	ft_ss(t_list *stack_a, t_list *stack_b);


#endif