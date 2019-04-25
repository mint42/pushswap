/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 07:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/25 06:38:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
static long		get_sum(t_snode *stack, int len)
{
	long		sum;
	t_snode		*cur;

	sum = 0;
	cur = stack;
	while (cur && len)
	{
		sum = sum + NUM(cur);
		cur = cur->next;
		--len;
	}
	return (sum);
}
*/

int				find_pivot(t_stack *stack, int len)
{
	t_snode		*cur;
	int			pivot;
	int			max;
	int			min;

	if (!stack || !(stack->top) || !len)
		return (-1);
	max = 0;
	min = 0;
	stack_extremes(stack, len, &max, &min);
	cur = stack->top;
	pivot = NUM(cur);
	while (cur && len)
	{
		pivot = NUM(cur);
		if (pivot != max && pivot != min)
			break ;
		--len;
		cur = cur->next;
	}
	return (pivot);
}
