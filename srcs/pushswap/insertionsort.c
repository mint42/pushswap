/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:36:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 02:07:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertionsort.h"
#include "stack.h"
#include "ft_stack.h"

static void		undo_rotations(t_stack *a, int rots)
{
	while (rots)
	{
		rra(a, 0, 1);
		--rots;
	}
}

int				insertionsort_a(t_stack *a, t_stack *b, int len_a, int len_b)
{
	if (!len_a || len_a == 1)
		return (0);
	while (len_a > 2 && !issort(a, len_a))
	{
		pb(a, b, 1);
		--len_a;
		++len_b;
	}
	if (len_a > 1 && NUM(a->top) > NUM(a->top->next))
		sa(a, 0, 1);
	return (insertionsort_b(a, b, len_a, len_b));
}

int				insertionsort_b(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int		rots;

	if (!len_b)
		return (0);
	rots = 0;
	while (len_b)
	{
		if (len_b > 1 && NUM(b->top) < NUM(b->top->next))
			sb(0, b, 1);
		while (rots < len_a && NUM(a->top) < NUM(b->top))
		{
			ra(a, 0, 1);
			++rots;
		}
		while (rots && (*(int *)ft_stack_peek_bottom(a)) > NUM(b->top))
		{
			rra(a, 0, 1);
			--rots;
		}
		pa(a, b, 1);
		--len_b;
		++len_a;
	}
	undo_rotations(a, rots);
	return (0);
}
