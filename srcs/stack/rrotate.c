/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 08:18:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_utils.h"
#include "ft_printf.h"

void	rra(t_stack *a, t_stack *b, int print)
{
	t_snode		*bottom;
	t_snode		*cur;

	if (!a || !(a->top) || !(a->top->next))
		return ;
	(void)b;
	cur = a->top;
	while (cur->next->next)
		cur = cur->next;
	bottom = cur->next;
	cur->next = 0;
	bottom->next = a->top->next;
	a->top->next = bottom;
	ft_swap(&NUM(a->top), &NUM(bottom));
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *a, t_stack *b, int print)
{
	t_snode		*bottom;
	t_snode		*cur;

	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	cur = b->top;
	while (cur->next->next)
		cur = cur->next;
	bottom = cur->next;
	cur->next = 0;
	bottom->next = b->top->next;
	b->top->next = bottom;
	ft_swap(&NUM(b->top), &NUM(bottom));
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, b, 0);
	rrb(a, b, 0);
	if (print)
		ft_printf("rrr\n");
}
