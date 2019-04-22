/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:48:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 03:30:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_stack.h"

# define NUM(snode) (*((int *)(snode->content)))

int			get_stack(t_stack *stack, char **argv, int argc);
int			stack_len(t_stack *stack);
int			issort(t_stack *stack);
int			issortr(t_stack *stack);
void		print_stack(t_stack *stack);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *a, t_stack *b);
void		sb(t_stack *a, t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		ra(t_stack *a, t_stack *b);
void		rb(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a, t_stack *b);
void		rrb(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

#endif
