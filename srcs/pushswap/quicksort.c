/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 07:41:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "quicksort.h"
#include "operations.h"
#include "issort.h"
#include "ft_stack.h"
#include "ft_printf.h"

static void		undo_rotations(t_stack *stack, int rots, int aorb)
{
	if (aorb == STACK_A)
	{
		while (rots)
		{
			rra(stack, 0, 1);
			--rots;
		}
	}
	else
	{
		while (rots)
		{
			rrb(0, stack, 1);
			--rots;
		}
	}
}

int				quicksort_a(t_stack *a, t_stack *b, int len, int rr)
{
	int		rots;
	int		pivot;
	int		i;

	if ((pivot = get_pivot(a, len, STACK_A)) == -1)
		return (0);
	rots = 0;
	i = len;
	while (a->top && i && !(issort(a, len) && !rots))
	{
		if (NUM(a->top) < pivot)
		{
			pb(a, b, 1);
			--len;
		}
		else
		{
			ra(a, b, 1);
			++rots;
		}
		--i;
	}
	if (rr)
		undo_rotations(a, rots, STACK_A);
	return (len);
}

int				quicksort_b(t_stack *a, t_stack *b, int len, int rr)
{
	int		rots;
	int		pivot;
	int		i;

	if ((pivot = get_pivot(b, len, STACK_B)) == -1)
		return (0);
	rots = 0;
	i = len;
	while (b->top && i && !(issortr(b, len) && !rots))
	{
		if (NUM(b->top) > pivot)
		{
			pa(a, b, 1);
			--len;
		}
		else
		{
			rb(a, b, 1);
			++rots;
		}
		--i;
	}
	if (rr)
		undo_rotations(b, rots, STACK_B);
	return (len);
}