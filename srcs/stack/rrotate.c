/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/07 04:30:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

void	rra(t_stack *a, t_stack *b, int print)
{
	if (!a || !(a->top) || !(a->top->next))
		return ;
	(void)b;
	ft_stack_rrotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *a, t_stack *b, int print)
{
	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	ft_stack_rrotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, 0, 0);
	rrb(0, b, 0);
	if (print)
		ft_printf("rrr\n");
}
