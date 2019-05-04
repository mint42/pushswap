/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 05:04:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 08:37:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_stack		t_stack;

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
