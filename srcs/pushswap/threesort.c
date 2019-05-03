/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_THIRD(a).c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:51:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 04:24:04 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

int				threesort_a(t_stack *a, int len)
{
	if (!len || len == 1)
		return (0);
	if (len == 2 && FIRST(a) > SECOND(a))
		sa(a, 0, 1);
	if (len == 2)
		return (0);
	if (FIRST(a) < SECOND(a) && FIRST(a) < THIRD(a) && SECOND(a) > THIRD(a))
	{
		sa(a, 0, 1);
		ra(a, 0, 1);
	}
	if (FIRST(a) > SECOND(a) && FIRST(a) < THIRD(a) && SECOND(a) < THIRD(a))
		sa(a, 0, 1);
	if (FIRST(a) < SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) > THIRD(a))
		rra(a, 0, 1);
	if (FIRST(a) > SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) < THIRD(a))
		ra(a, 0, 1);
	if (FIRST(a) > SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) > THIRD(a))
	{
		sa(a, 0, 1);
		rra(a, 0, 1);
	}
	return (0);
}

static void		twosort_b(t_stack *a, t_stack *b, int len)
{
	if (len == 2)
	{
		if (FIRST(b) > SECOND(b))
			sb(a, b, 1);
		pa(a, b, 1);
	}
	pa(a, b, 1);
}

int				threesort_b(t_stack *a, t_stack *b, int len)
{
	if (!len)
		return (0);
	if (len < 3)
	{
		twosort(a, b, len);
		return (0);
	}
	if (FIRST(b) < SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) < THIRD(b))
	{
		sb(a, b, 1);
		rrb(a, b, 1);
	}
	if (FIRST(b) < SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) > THIRD(b))
		rb(a, b, 1);
	if (FIRST(b) > SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) < THIRD(b))
		rrb(a, b, 1);
	if (FIRST(b) < SECOND(b) && FIRST(b) > THIRD(b) && SECOND(b) > THIRD(b))
		sb(a, b, 1);
	pa(a, b, 1);
	if (FIRST(b) > SECOND(b) && FIRST(b) > THIRD(b) && SECOND(b) < THIRD(b))
		sb(a, b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	return (0);
}
