/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 05:10:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 10:51:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threesort.h"
#include "operations.h"
#include "ft_stack.h"

static void		twosort_b(t_stack *a, t_stack *b, int len_b)
{
	if (len_b == 2)
	{
		if (FIRST(b) < SECOND(b))
			sb(0, b, 1);
		pa(a, b, 1);
	}
	pa(a, b, 1);
}

int				threesort_b(t_stack *a, t_stack *b, int len_b)
{
	if (!len_b)
		return (0);
	if (len_b < 3)
	{
		twosort_b(a, b, len_b);
		return (0);
	}
	if (FIRST(b) < SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) < THIRD(b))
	{
		sb(0, b, 1);
		rrb(0, b, 1);
	}
	if (FIRST(b) < SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) > THIRD(b))
		rb(0, b, 1);
	if (FIRST(b) > SECOND(b) && FIRST(b) < THIRD(b) && SECOND(b) < THIRD(b))
		rrb(0, b, 1);
	if (FIRST(b) < SECOND(b) && FIRST(b) > THIRD(b) && SECOND(b) > THIRD(b))
		sb(0, b, 1);
	pa(a, b, 1);
	if (FIRST(b) < SECOND(b))
		sb(a, b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	return (0);
}

int				threesort_a(t_stack *a, int len_a)
{
	if (!len_a || len_a == 1)
		return (0);
	if (len_a == 2 && FIRST(a) > SECOND(a))
		sa(a, 0, 1);
	if (len_a == 2)
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
