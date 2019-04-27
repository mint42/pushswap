/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/26 21:27:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>


static void		undo_rotations_a(t_stack *a, int rots_a)
{
	while (rots_a)
	{
		rra(a, 0, 1);
		--rots_a;
	}
}

static void		undo_rotations_b(t_stack *b, int rots_b)
{
	while (rots_b)
	{
		rrb(0, b, 1);
		--rots_b;
	}
}

static int		quicksort_a(t_stack *a, t_stack *b, int len_a)
{
	int		rots_a;
	int		pivot;
	int		i;

	if (len_a == 1)
	{
		if (stack_len(a) > 1)
			ra(a, b, 1);
		return (0);
	}
	pivot = find_pivot(a, len_a, A);
	if (pivot == -1)
		return (0);
	rots_a = 0;
	i = len_a;
	while (a->top && i)
	{
		if (NUM(a->top) > pivot)
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
	undo_rotations_a(a, rots_a);
	return (len_a);
}

static int		quicksort_b(t_stack *a, t_stack *b, int len_b)
{
	int		rots_b;
	int		pivot;
	int		i;

	if (len_b == 1)
	{
		pa(a, b, 1);
		ra(a, b, 1);
		return (0);
	}
	pivot = find_pivot(b, len_b, B);
	if (pivot == -1)
		return (0);
	rots_b = 0;
	i = len_b;
	while (b->top && i)
	{
		if (NUM(b->top) < pivot)
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
	undo_rotations_b(b, rots_b);
	return (len_b);
}

static void		sort_b(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!b || !b->top)
		return ;
	len_b = quicksort_b(a, b, len);
	if (len_b == 0)
		len_a = 0;
	else
		len_a = len - len_b;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}

void			sort_a(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!a || !a->top)
		return ;
	len_a = quicksort_a(a, b, len);
	if (len_a == 0)
		len_b = 0;
	else
		len_b = len - len_a;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}
