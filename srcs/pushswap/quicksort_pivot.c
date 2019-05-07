/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 04:30:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/07 13:45:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_math.h"

static int		try_pivot(t_stack *stack, int len, int pivot)
{
	t_snode		*cur;
	int			more;
	int			less;

	cur = stack->top;
	more = 0;
	less = 0;
	while (cur && len)
	{
		if (NUM(cur) > pivot)
			++more;
		else
			++less;
		cur = cur->next;
		--len;
	}
	if (ft_abs(more - less) < 2)
		return (1);
	return (0);
}

int				get_pivot(t_stack *stack, int len)
{
	t_snode		*cur;
	int			i;
	int			pivot;

	cur = stack->top;
	i = len;
	while (cur && i)
	{
		pivot = NUM(cur);
		if (try_pivot(stack, len, pivot))
			break ;
		cur = cur->next;
		--i;
	}
	return (pivot);
}
