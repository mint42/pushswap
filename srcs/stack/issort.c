/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:01:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 04:15:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

int		issort(t_stack *stack)
{
	t_snode		*cur;
	int			len;
	int			ro;

	if (!stack || !(stack->top))
		return (-1);
	len = 0;
	ro = 0;
	cur = stack->top;
	while (cur->next)
	{
		if (NUM(cur) > NUM(cur->next))
		{
			if (!ro)
				ro = len;
			else
				return (-1);
		}
		++len;
		cur = cur->next;
	}
	return (ro);
}
