/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:09:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 06:45:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"

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

int		ro_index(t_stack *stack)
{
	t_snode		*cur;
	int			i;
	int			ro;

	if (!stack || !(stack->top))
		return (-1);
	i = 0;
	ro = 0;
	cur = stack->top;
	while (cur->next)
	{
		++i;
		if (NUM(cur) > NUM(cur->next))
		{
			if (!ro)
				ro = i;
			else
				return (-1);
		}
		cur = cur->next;
	}
	if (ro && NUM(stack->top) < NUM(cur))
		return (-1);
	return (ro);
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

int		rro_index(t_stack *stack)
{
	t_snode		*cur;
	int			i;
	int			rro;

	if (!stack || !(stack->top))
		return (-1);
	i = 0;
	rro = 0;
	cur = stack->top;
	while (cur->next)
	{
		++i;
		if (NUM(cur) < NUM(cur->next))
		{
			if (!rro)
				rro = i;
			else
				return (-1);
		}
		cur = cur->next;
	}
	if (rro && (NUM(stack->top) > NUM(cur)))
		return (-1);
	return (rro);
}
