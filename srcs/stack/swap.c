/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:54:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:25:06 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_utils.h"
#include "ft_printf.h"

void	sa(t_stack *a, t_stack *b, int print)
{
	if (!a || !(a->top) || !(a->top->next))
		return ;
	(void)b;
	ft_stack_swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *a, t_stack *b, int print)
{
	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	ft_stack_swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0, 0);
	sb(0, b, 0);
	if (print)
		ft_printf("ss\n");
}
