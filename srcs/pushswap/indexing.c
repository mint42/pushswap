/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 08:25:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 09:11:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

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

int		sort_index(t_stack *stack)
{
	t_snode		*cur;
	int			sort;
	int			i;

	if (!stack || !(stack->top))
		return (-1);
	i = 0;
	sort = 0;
	cur = stack->top;
	while (cur->next)
	{
		++i;
		if (NUM(cur) > NUM(cur->next))
			sort = i;
		cur = cur->next;
	}
	return (sort);
}
