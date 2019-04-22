/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:50:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 23:50:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ra(t_stack *a, t_stack *b)
{
	t_snode		*top;
	t_snode		*cur;

	if (!a || !(a->top))
		return ;
	(void)b;
	top = a->top;
	cur = a->top;
	while (cur->next)
		cur = cur->next;
	a->top = a->top->next;
	cur->next = top;
	top->next = 0;
}

void	rb(t_stack *a, t_stack *b)
{
	t_snode		*top;
	t_snode		*cur;

	if (!b || !(b->top))
		return ;
	(void)a;
	top = b->top;
	cur = b->top;
	while (cur->next)
		cur = cur->next;
	b->top = b->top->next;
	cur->next = top;
	top->next = 0;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}
