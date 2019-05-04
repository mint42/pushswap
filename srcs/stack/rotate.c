/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:50:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:26:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

void	ra(t_stack *a, t_stack *b, int print)
{
	if (!a || !(a->top) || !(a->top->next))
		return ;
	(void)b;
	ft_stack_rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack *a, t_stack *b, int print)
{
	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	ft_stack_rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, 0, 0);
	rb(0, b, 0);
	if (print)
		ft_printf("rr\n");
}
