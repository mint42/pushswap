/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 23:53:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_utils.h"

void	rra(t_stack *a, t_stack *b)
{
	t_snode		*bottom;
	t_snode		*cur;

	if (!a || !(a->top))
		return ;
	(void)b;
	cur = a->top;
	while (cur->next->next)
		cur = cur->next;
	bottom = cur->next;
	cur->next = 0;
	bottom->next = a->top->next;
	a->top->next = bottom->next;
	ft_swap(&NUM(a->top), &NUM(bottom));
}

void	rrb(t_stack *a, t_stack *b)
{
	t_snode		*bottom;
	t_snode		*cur;

	if (!b || !(b->top))
		return ;
	(void)a;
	cur = b->top;
	while (cur->next->next)
		cur = cur->next;
	bottom = cur->next;
	cur->next = 0;
	bottom->next = b->top->next;
	b->top->next = bottom->next;
	ft_swap(&NUM(b->top), &NUM(bottom));
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
