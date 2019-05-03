/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 03:42:20 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 03:56:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

int		issort(t_stack *stack, int len)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return (-1);
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
