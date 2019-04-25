/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/25 10:03:39 by rreedy           ###   ########.fr       */
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

static int		even_out_a(t_stack *a, t_stack *b, int rots_a, int pivot)
{
	int		pushed;

	pushed = 0;
	while (a->top && b->top && rots_a)
	{
		if (NUM(a->top) > pivot)
		{
			pb(a, b, 1);
			++pushed;
		}
		else
		{
			ra(a, b, 1);
			--rots_a;
		}
	}
	return (pushed);
}

static int		even_out_b(t_stack *a, t_stack *b, int rots_b, int pivot)
{
	int		pushed;

	pushed = 0;
	while (a->top && b->top && rots_b)
	{
		if (NUM(b->top) < pivot)
		{
			++pushed;
			pa(a, b, 1);
		}
		else
		{
			rb(a, b, 1);
			--rots_b;
		}
	}
	return (pushed);
}

static void		undo_rotations_b(t_stack *b, int rots_b)
{
	while (rots_b)
	{
		rrb(0, b, 1);
		--rots_b;
	}
}

static void		undo_rotations_a(t_stack *a, int rots_a)
{
	while (rots_a)
	{
		rra(a, 0, 1);
		--rots_a;
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

static void		splitstack_b(t_stack *a, t_stack *b, int half)
{
	int		i;

	i = 0;
	while (i < half)
	{
		pa(a, b, 1);
		++i;
	}
}

static int		quicksort_a(t_stack *a, t_stack *b, int len_a)
{
	int		stack_rotated;
	int		rots_a;
	int		rots_b;
	int		pivot;
	int		half;

	ft_printf("sort_a\nlen_a: %d\n", len_a);
	print_stack(a, stack_len(a));
	print_stack(b, stack_len(b));
	ft_printf("a stack\n");
	print_stack(a, len_a);
	if (len_a == 1)
	{
		if (stack_len(a) > 1)
			ra(a, b, 1);
		return (-1);
	}
	if (len_a == 2)
	{
		if (NUM(a->top) > NUM(a->top->next))
		{
			sa(a, b, 1);
		}
		if (stack_len(a) > 2)
		{
			ra(a, b, 1);
			ra(a, b, 1);
		}
		return (-1);
	}
	pivot = find_pivot(a, len_a);
	ft_printf("pivot: %d\n", pivot);
	half = (len_a / 2) + (len_a % 2);
	len_a = len_a - half;
	if (pivot == -1)
		return (0);
	splitstack_a(a, b, half);
	rots_a = len_a;
	rots_b = half;
	while (a->top && b->top && rots_a && rots_b)
	{
		stack_rotated = compare_and_execute(a, b, pivot);
		if (stack_rotated == A || stack_rotated == (A + B))
			--rots_a;
		if (stack_rotated >= B)
			--rots_b;
	}
	if (rots_a)
		len_a = len_a - even_out_a(a, b, rots_a, pivot);
	else if (rots_b)
		len_a = len_a + even_out_b(a, b, rots_b, pivot);
	undo_rotations_b(b, half - rots_b);
	return (len_a);
}

static int		quicksort_b(t_stack *a, t_stack *b, int len_b)
{
	int		stack_rotated;
	int		rots_a;
	int		rots_b;
	int		pivot;
	int		half;

	ft_printf("sort_b\nlen_b: %d\n", len_b);
	print_stack(a, stack_len(a));
	print_stack(b, stack_len(b));
	ft_printf("b stack\n");
	print_stack(b, len_b);
	if (len_b == 1)
	{
		pa(a, b, 1);
		ra(a, b, 1);
		return (-1);
	}
	if (len_b == 2)
	{
		if (NUM(b->top) < NUM(b->top->next))
			sb(a, b, 1);
		pa(a, b, 1);
		pa(a, b, 1);
		ra(a, b, 1);
		ra(a, b, 1);
		return (-1);
	}
	pivot = find_pivot(b, len_b);
	ft_printf("pivot: %d\n", pivot);
	half = (len_b / 2) + (len_b % 2);
	splitstack_b(a, b, half);
	rots_a = half;
	rots_b = len_b;
	while (a->top && b->top && rots_a && rots_b)
	{
		stack_rotated = compare_and_execute(a, b, pivot);
		if (stack_rotated >= A)
			--rots_a;
		if (stack_rotated >= B)
			--rots_b;
	}
	if (rots_a)
		len_b = len_b + even_out_a(a, b, rots_a, pivot);
	else if (rots_b)
		len_b = len_b - even_out_b(a, b, rots_b, pivot);
	undo_rotations_a(a, half - rots_a);
	return (len_b);
}


static void		sort_b(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!b || !b->top)
		return ;
	len_b = quicksort_b(a, b, len);
	len_a = len - len_b;
	ft_printf("len_a = %d - %d\n", len, len_b);
	if (len_b == -1 && len_b != 0 )
		return ;
	sort_a(a, b, len_a);
	sort_b(a, b, len_b);
}

void			sort_a(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!a || !a->top)
		return ;
	len_a = quicksort_a(a, b, len);
	len_b = len - len_a;
	ft_printf("len_b = %d - %d\n", len, len_a);
	if (len_a == -1 && len_a != 0 )
		return ;
	sort_a(a, b, len_a);
	sort_b(a, b, len_b);
}
