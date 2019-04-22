/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:54:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 23:54:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_utils.h"

void	sa(t_stack *a, t_stack *b)
{
	if (!a || !(a->top))
		return ;
	(void)b;
	ft_swap(&NUM(a->top), &NUM(a->top->next));
}

void	sb(t_stack *a, t_stack *b)
{
	if (!b || !(b->top))
		return ;
	(void)a;
	ft_swap(&NUM(b->top), &NUM(b->top->next));
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
