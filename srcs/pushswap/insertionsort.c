/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:36:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/05 07:34:46 by rreedy           ###   ########.fr       */
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

int				insertionsort_b(t_stack *a, t_stack *b, int len_a, int len_b)
{
	if (!len_b)
		return (0);
	while (len_b)
	{
		if (issortrro(b, ft_stack_len(b)))
			rotatesort_b(a, b, ft_stack_len(b), 0);
		if (NUM(a->top) < NUM(b->top))
			while (NUM(a->top) < NUM(b->top))
				ra(a, 0, 1);
		else if ((*(int *)ft_stack_peek_bottom(a)) > NUM(b->top))
			while ((*(int *)ft_stack_peek_bottom(a)) > NUM(b->top))
				rra(a, 0, 1);
		pa(a, b, 1);
		--len_b;
		++len_a;
	}
	return (0);
}
