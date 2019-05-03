/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 04:28:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "quicksort.h"
#include "ft_stack.h"

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

int				quicksort_a(t_stack *a, t_stack *b, int len_a)
{
	int		rots_a;
	int		pivot;
	int		i;

	if (len_a == 1)
		return (0);
	if ((pivot = get_pivot(a, len_a, STACK_A)) == -1)
		return (0);
	rots_a = 0;
	i = len_a;
	while (a->top && i)
	{
		if (NUM(a->top) < pivot)
		{
			pb(a, b, 1);
			--len_a;
		}
		else
		{
			ra(a, b, 1);
			++rots_a;
		}
		--i;
	}
	undo_rotations(a, rots_a, STACK_A);
	return (len_a);
}

int				quicksort_b(t_stack *a, t_stack *b, int len_b)
{
	int		rots_b;
	int		pivot;
	int		i;

	if (len_b == 1)
	{
		pa(a, b, 1);
		return (0);
	}
	if ((pivot = get_pivot(b, len_b, STACK_B)) == -1)
		return (0);
	rots_b = 0;
	i = len_b;
	while (b->top && i)
	{
		if (NUM(b->top) > pivot)
		{
			pa(a, b, 1);
			--len_b;
		}
		else
		{
			rb(a, b, 1);
			++rots_b;
		}
		--i;
	}
	undo_rotations(b, rots_b, STACK_B);
	return (len_b);
}
