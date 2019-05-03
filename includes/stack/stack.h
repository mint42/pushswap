/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:48:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 23:59:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_stack.h"

# define NUM(snode) (*((int *)(snode->content)))

int			get_stack(t_stack *stack, char **argv, int argc);
int			stack_len(t_stack *stack);
int			issort(t_stack *stack, int len);
int			issortr(t_stack *stack);
void		stack_extremes(t_stack *stack, int len, int *max, int *min);
void		print_stack(t_stack *stack, int len);
void		pa(t_stack *a, t_stack *b, int print);
void		pb(t_stack *a, t_stack *b, int print);
void		sa(t_stack *a, t_stack *b, int print);
void		sb(t_stack *a, t_stack *b, int print);
void		ss(t_stack *a, t_stack *b, int print);
void		ra(t_stack *a, t_stack *b, int print);
void		rb(t_stack *a, t_stack *b, int print);
void		rr(t_stack *a, t_stack *b, int print);
void		rra(t_stack *a, t_stack *b, int print);
void		rrb(t_stack *a, t_stack *b, int print);
void		rrr(t_stack *a, t_stack *b, int print);

#endif
