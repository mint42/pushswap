/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:54:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 04:06:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_utils.h"

void	sa(t_stack *a, t_stack *b)
{
	if (!a || !(a->top) || !(a->top->next))
		return ;
	(void)b;
	ft_swap(&NUM(a->top), &NUM(a->top->next));
}

void	sb(t_stack *a, t_stack *b)
{
	if (!b || !(b->top) || !(b->top->next))
		return ;
	(void)a;
	ft_swap(&NUM(b->top), &NUM(b->top->next));
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
