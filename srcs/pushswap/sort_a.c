/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 03:21:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 10:15:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>

static void		swap_tops(t_stack *a, t_stack *b)
{
	pa(a, b, 1);
	sa(a, b, 1);
	pb(a, b, 1);
	rr(a, b, 1);
}

static void		even_out_a(t_stack *a, t_stack *b, int rots_a, int pivot, int half)
{
	while (a->top && b->top && rots_a < half)
	{
		if (NUM(a->top) > pivot)
			pb(a, b, 1);
		else
		{
			ra(a, b, 1);
		}
		++rots_a;
	}
}

static void		even_out_b(t_stack *a, t_stack *b, int rots_b, int pivot, int half)
{
	while (a->top && b->top && rots_b < half)
	{
		if (NUM(a->top) < pivot)
			pa(a, b, 1);
		else
		{
			rb(a, b, 1);
		}
		++rots_b;
	}
}

static void		undo_rotations(t_stack *b, int rots_b)
{
	while (rots_b)
	{
		rrb(0, b, 1);
		--rots_b;
	}
}

static int		compare_and_execute(t_stack *a, t_stack *b, int pivot)
{
	if (NUM(a->top) > pivot)
	{
		if (NUM(b->top) < pivot)
		{
			swap_tops(a, b);
			return (A + B);
		}
		else
		{
			rb(a, b, 1);
			return (B);
		}
	}
	else if (NUM(b->top) < pivot)
	{
		ra(a, b, 1);
		return (A);
	}
	rr(a, b, 1);
	return (A + B);
}

static void		quicksort_a(t_stack *a, t_stack *b, int half, int pivot)
{
	int		stack_rotated;
	int		rots_a;
	int		rots_b;

	rots_a = 0;
	rots_b = 0;
	while (a->top && b->top && rots_a < half && rots_b < half)
	{
		stack_rotated = compare_and_execute(a, b, pivot);
		if (stack_rotated == A || stack_rotated == (A + B))
			++rots_a;
		if (stack_rotated >= B)
			++rots_b;
	}
	if (rots_a < half)
		even_out_a(a, b, rots_a, pivot, half);
	else if (rots_b < half)
		even_out_b(a, b, rots_b, pivot, half);
	undo_rotations(b, rots_b);
}

static void		splitstack_a(t_stack *a, t_stack *b, int half)
{
	int		i;

	i = 0;
	while (i < half)
	{
		pb(a, b, 1);
		++i;
	}
}

void			sort_a(t_stack *a, t_stack *b, int len)
{
	int		pivot;
	int		half;

	if (!a || !a->top || !a->top->next)
		return ;
	half = (len / 2) + (len % 2);
	pivot = find_pivot(a, len);
	splitstack_a(a, b, half);
	quicksort_a(a, b, half, pivot);
	sort_a(a, b, half);
	sort_b(a, b, half);
}
