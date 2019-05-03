/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 02:38:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 04:21:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"

/*
void	bubblesort_b(t_stack *b, t_stack *a)
{
	int		ro;

	ro = -1;
	while (b && b->top)
	{
		ro = issortr(b);
		if (b->top && b->top->next && NUM(b->top) < NUM(b->top->next))
		{
			sb(a, b);
			ft_printf("sb\n");
		}
		else
		{
			pa(a, b);
			ft_printf("pa\n");
			if (issort(a) >= 0)
				sorta(a, b);
		}
	}
	if (ro > 0)
		rot(b, ro, 'b');
}

void	bubblesort(t_stack *a, t_stack *b, int len_a)
{
	int		rots;

	while (a && a->top)
	{
		ro = issort(a);
		if (ro >= 0)
			break ;
		if (a->top && a->top->next && NUM(a->top) > NUM(a->top->next))
		{
			sa(a, b);
			ft_printf("sa\n");
		}
		else
		{
			pb(a, b);
			ft_printf("pb\n");
		}
	}
	if (ro > 0)
		rot(a, ro, 'a');
}
*/
