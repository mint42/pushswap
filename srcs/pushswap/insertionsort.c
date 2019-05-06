/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:36:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 07:56:19 by rreedy           ###   ########.fr       */
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

/*
static int		find_location(t_stack *a, int len_a, int num)
{
	t_snode		*cur;
	int			ro;
	int			location;

	if (!a || !(a->top))
		return (0);
	location = 0;
	cur = a->top;
	ro = ro_index(a);
	if (ro == -1)
		return (-1);
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
	}
	if (location == len_a)
		return (0);
	return (location);
}
*/

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

static int		find_location(t_stack *a, int len_a, int num)
{
	t_snode		*cur;
	int			ro;
	int			location;

	if (!a || !(a->top))
		return (0);
	location = 0;
	cur = a->top;
	ro = ro_index(a);
	if (ro == -1)
		return (-1);
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
	}
	if (location == len_a)
		return (0);
	return (location);
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
	if (!len_a || len_a == 1)
		return (0);
	while (len_a > 3 && !issort(a, len_a) && ro_index(a) == -1)
	{
		pb(a, b, 1);
		--len_a;
		++len_b;
	}
	if (len_a <= 3)
		threesort_a(a, len_a);
	else if (ro_index(a) > 0)
		rotatesort_a(a, len_a);
	return (insertionsort_b(a, b, len_a, len_b));
}
