/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:01:30 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:55:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		issort(t_stack *stack)
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
		if (stack->num > stack->next->num)
		{
			if (max == stack->num && min == stack->next->num)
				ro = len - stacklen(stack->next);
			else 
				return (-1);
		}
		stack = stack->next;
	}
	return (ro);
}