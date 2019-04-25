/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_extremes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 06:29:04 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/25 06:38:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_extremes(t_stack *stack, int len, int *max, int *min)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return ;
	cur = stack->top;
	*max = NUM(cur);
	*min = NUM(cur);
	while (cur && len)
	{
		if (NUM(cur) > *max)
			*max = NUM(cur);
		if (NUM(cur) < *min)
			*min = NUM(cur);
		cur = cur->next;
	}
}
