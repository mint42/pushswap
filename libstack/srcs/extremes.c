/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:48:59 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:44:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		extremes(t_stack *stack, int *min, int *max)
{
	*min = stack->num;
	*max = stack->num;
	while (stack)
	{
		if (stack->num > *max)
			*max = stack->num;
		if (stack->num < *min)
			*min = stack->num;
		stack = stack->next;
	}
}
