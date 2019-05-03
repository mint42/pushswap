/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:01:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 03:42:01 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

int		issortro(t_stack *stack, int len)
{
	t_snode		*cur;
	int			rlen;
	int			ro;

	if (!stack || !(stack->top))
		return (-1);
	rlen = 0;
	ro = 0;
	cur = stack->top;
	while (cur->next && len)
	{
		++rlen;
		--len;
		if (NUM(cur) > NUM(cur->next))
		{
			if (!ro)
				ro = rlen;
			else
				return (-1);
		}
		cur = cur->next;
	}
	if (ro && (NUM(stack->top) < NUM(cur)))
		return (-1);
	return (ro);
}
