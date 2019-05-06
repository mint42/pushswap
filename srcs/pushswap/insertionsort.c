/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:36:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 10:51:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "indexing.h"
#include "threesort.h"
#include "rotatesort.h"
#include "insertionsort.h"
#include "stack.h"
#include "operations.h"
#include "ft_stack.h"

static void		rotate_to_location(t_stack *a, int len_a, int location)
{
	if (location <= (len_a / 2))
	{
		while (location > 0)
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

static int		get_location(t_snode *cur, int num, int ro)
{
	int		location;

	location = 0;
	while (ro && cur && num > NUM(cur))
	{
		cur = cur->next;
		++location;
		--ro;
	}
	return (location);
}

static int		find_location(t_stack *a, int len_a, int num)
{
	t_snode		*cur;
	int			ro;
	int			location;

	if (!a || !(a->top))
		return (0);
	cur = a->top;
	location = 0;
	ro = ro_index(a);
	if (ro == -1)
		return (-1);
	if (!ro)
		ro = len_a;
	if (num < NUM(a->top))
	{
		while (location < ro)
		{
			cur = cur->next;
			++location;
		}
		ro = len_a - ro;
	}
	location = location + get_location(cur, num, ro);
	return ((location != len_a) ? location : 0);
}

int				insertionsort_b(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int		location;

	if (!len_b)
		return (0);
	while (len_b)
	{
		if (rro_index(b) > 0)
			rotatesort_b(a, b, ft_stack_len(b), 0);
		location = find_location(a, len_a, NUM(b->top));
		rotate_to_location(a, len_a, location);
		pa(a, b, 1);
		--len_b;
		++len_a;
	}
	rotatesort_a(a, len_a);
	return (0);
}

int				insertionsort_a(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int		sort;

	if (!len_a || len_a == 1)
		return (0);
	sort = sort_index(a);
	if (sort == -1)
		return (0);
	while (len_a > 3 && sort && ro_index(a) == -1)
	{
		pb(a, b, 1);
		--len_a;
		++len_b;
		--sort;
	}
	if (len_a <= 3)
		threesort_a(a, len_a);
	else if (ro_index(a) > 0)
		rotatesort_a(a, len_a);
	return (insertionsort_b(a, b, len_a, len_b));
}
