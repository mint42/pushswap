/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issortr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:40:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:25:06 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include <stddef.h>

int		issortr(t_stack *stack)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return (0);
	cur = stack->top;
	while (cur->next)
	{
		if (NUM(cur) < NUM(cur->next))
			return (0);
		cur = cur->next;
	}
	return (1);
}
