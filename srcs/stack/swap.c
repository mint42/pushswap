/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:54:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 08:19:40 by rreedy           ###   ########.fr       */
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
	ft_swap(&NUM(a->top), &NUM(a->top->next));
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *a, t_stack *b, int print)
{
	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	ft_swap(&NUM(b->top), &NUM(b->top->next));
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, b, 0);
	sb(a, b, 0);
	if (print)
		ft_printf("ss\n");
}
