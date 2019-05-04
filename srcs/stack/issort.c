/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 05:00:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 06:07:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "issort.h"
#include "ft_stack.h"

int		issort(t_stack *stack, int len)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return (1);
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

int		issortro(t_stack *stack, int len)
{
	t_snode		*cur;
	int			rlen;
	int			ro;

	if (!stack || !(stack->top))
		return (1);
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
				return (0);
		}
		cur = cur->next;
	}
	if (ro && (NUM(stack->top) < NUM(cur)))
		return (0);
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

int		issortrro(t_stack *stack, int len)
{
	t_snode		*cur;
	int			rlen;
	int			rro;

	if (!stack || !(stack->top))
		return (1);
	rlen = 0;
	rro = 0;
	cur = stack->top;
	while (cur->next && len)
	{
		++rlen;
		--len;
		if (NUM(cur) < NUM(cur->next))
		{
			if (!rro)
				rro = rlen;
			else
				return (0);
		}
		cur = cur->next;
	}
	if (rro && (NUM(stack->top) > NUM(cur)))
		return (0);
	return (rro);
}
