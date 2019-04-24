/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 07:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 10:22:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static long		get_sum(t_snode *stack)
{
	long		sum;
	t_snode		*cur;

	sum = 0;
	cur = stack;
	while (cur)
	{
		sum = sum + NUM(cur);
		cur = cur->next;
	}
	return (sum);
}

int				find_pivot(t_stack *stack)
{
	t_snode		*cur;
	int			pivot;
	long		left;
	long		right;

	if (!stack || !(stack->top))
		return (-1);
	cur = stack->top;
	left = 0;
	pivot = NUM(cur);
	cur = cur->next;
	right = get_sum(cur);
	while (cur && left < right)
	{
		left = left + pivot;
		pivot = NUM(cur);
		right = right - pivot;
		cur = cur->next;
	}
	return (pivot);
}
