/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:19:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/02 11:00:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libs/libft.h"

t_list				*ft_init_a(int size, char **numbers, t_list *stack_a);
t_list *ft_sa(t_list *stack_a);
t_list *ft_ra(t_list *stack_a);

#endif