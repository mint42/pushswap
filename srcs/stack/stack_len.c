/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 03:28:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 03:30:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		stack_len(t_stack *stack)
{
	t_snode		*cur;
	int			len;

	if (!stack || !(stack->top))
		return (0);
	len = 0;
	cur = stack->top;
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	return (len);
}
