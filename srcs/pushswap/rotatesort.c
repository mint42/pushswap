/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 04:27:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/05 14:24:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "issort.h"
#include "operations.h"
#include "ft_stack.h"

int		rotatesort_a(t_stack *a, int len_a)
{
	int		ro;

	ro = issortro(a, len_a);
	if (ro < (len_a / 2))
	{
		while (ro)
		{
			ra(a, 0, 1);
			--ro;
		}
	}
	else if (ro)
	{
		while (ro < len_a)
		{
			rra(a, 0, 1);
			++ro;
		}
	}
	return (0);
}

int		rotatesort_b(t_stack *a, t_stack *b, int len_b, int push_to_a)
{
	int		ro;

	ro = issortrro(b, len_b);
	if (ro <= (len_b / 2))
	{
		while (ro)
		{
			rb(0, b, 1);
			--ro;
		}
	}
	else if (ro)
	{
		while (ro < len_b)
		{
			rrb(0, b, 1);
			++ro;
		}
	}
	while (push_to_a && len_b)
	{
		pa(a, b, 1);
		--len_b;
	}
	return (0);
}
