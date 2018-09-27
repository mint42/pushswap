/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issortr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:40:02 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:09:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		issortr(t_stack *stack)
{
	int		min;
	int		max;
	int		len;
	int		ro;

	min = 0;
	max = 0;
	ro = 0;
	len = stacklen(stack);
	extremes(stack, &min, &max);
	while (stack && stack->next)
	{
		if (stack->num < stack->next->num)
		{
			if (min == stack->num && max == stack->next->num)
				ro = len - stacklen(stack);
			else
				return (-1);
		}
		stack = stack->next;
	}
	return (ro);
}
