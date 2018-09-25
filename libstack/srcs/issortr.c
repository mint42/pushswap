/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issortr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 10:40:02 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/25 10:52:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		issortr(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num < stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
