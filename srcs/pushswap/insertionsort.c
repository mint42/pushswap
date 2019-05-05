/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:36:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/05 14:55:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threesort.h"
#include "rotatesort.h"
#include "insertionsort.h"
#include "stack.h"
#include "operations.h"
#include "issort.h"
#include "ft_stack.h"
#include "ft_printf.h"

int				insertionsort_a(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int		total_len_a;

	if (!len_a || len_a == 1)
		return (0);
	total_len_a = ft_stack_len(a);
	while (len_a > 2 && total_len_a > 3 && !issort(a, len_a) &&
			!issortro(a, total_len_a))
	{
		pb(a, b, 1);
		--len_a;
		--total_len_a;
		++len_b;
	}
	if (total_len_a <= 3)
		threesort_a(a, total_len_a);
	else if (issortro(a, total_len_a))
		rotatesort_a(a, total_len_a);
	else if (len_a == 2 && NUM(a->top) > NUM(a->top->next))
		sa(a, 0, 1);
	return (insertionsort_b(a, b, len_a, len_b));
}

static int		find_location(t_stack *a, int len_a, int num)
{
	t_snode		*cur;
	int			ro;
	int			location;

	if (!a || !(a->top))
		return (0);
	location = 0;
	cur = a->top;
	ro = issortro(a, len_a);
	if (!ro)
		ro = len_a;
	if (cur && num < NUM(cur))
	{
		while (location < ro)
		{
			cur = cur->next;
			++location;
		}
		while (cur && num > NUM(cur))
		{
			cur = cur->next;
			++location;
		}
	}
	else
	{
		while (ro && cur && num > NUM(cur))
		{
			cur = cur->next;
			++location;
			--ro;
		}
	} if (location == len_a)
		return (0);
	return (location);
}

static void		rotate_to_location(t_stack *a, int len_a, int location)
{
	if (location <= (len_a / 2))
	{
		while (location)
		{
			ra(a, 0, 1);
			--location;
		}
	}
	else if (location)
	{
		while (location < len_a)
		{
			rra(a, 0, 1);
			++location;
		}
	}
}

int				insertionsort_b(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int		location;

	if (!len_b)
		return (0);
	while (len_b)
	{
		if (issortrro(b, ft_stack_len(b)))
			rotatesort_b(a, b, ft_stack_len(b), 0);
		location = find_location(a, len_a, NUM(b->top));
		ft_printf("location: %d\n", location);
		print_stack(a, ft_stack_len(a));
		print_stack(b, ft_stack_len(b));
		rotate_to_location(a, len_a, location);
		pa(a, b, 1);
		--len_b;
		++len_a;
	}
	rotatesort_a(a, len_a);
	return (0);
}
