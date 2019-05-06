/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 04:27:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 08:27:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "indexing.h"
#include "operations.h"
#include "ft_stack.h"

int		rotatesort_b(t_stack *a, t_stack *b, int len_b, int push_to_a)
{
	int		ro;

	ro = rro_index(b);
	if (ro <= (len_b / 2))
	{
		while (ro > 0)
		{
			rb(0, b, 1);
			--ro;
		}
	}
	else if (ro > 0)
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

int		rotatesort_a(t_stack *a, int len_a)
{
	int		ro;

	ro = ro_index(a);
	if (ro < (len_a / 2))
	{
		while (ro > 0)
		{
			ra(a, 0, 1);
			--ro;
		}
	}
	else if (ro > 0)
	{
		while (ro < len_a)
		{
			rra(a, 0, 1);
			++ro;
		}
	}
	return (0);
}
