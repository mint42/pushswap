/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:09:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 08:26:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

int		issort(t_stack *stack, int len)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return (0);
	cur = stack->top;
	while (cur->next && len)
	{
		--len;
		if (NUM(cur) > NUM(cur->next))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int		issortr(t_stack *stack, int len)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return (1);
	cur = stack->top;
	while (cur->next && len)
	{
		--len;
		if (NUM(cur) < NUM(cur->next))
			return (0);
		cur = cur->next;
	}
	return (1);
}
