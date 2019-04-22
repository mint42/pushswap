/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:47:42 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 03:31:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>

void	rot(t_stack *stack, int ro, char aorb)
{
	int		rro;

	rro = 0;
	if (ro > (stack_len(stack) / 2))
		rro = stack_len(stack) - ro;
	while (!rro && ro)
	{
		ra(stack, 0);
		ft_printf("r%c\n", aorb);
		--ro;
	}
	while (rro)
	{
		rra(stack, 0);
		ft_printf("rr%c\n", aorb);
		--rro;
	}
}

void	sorta(t_stack *a, t_stack *b)
{
	int		ro;

	ro = -1;
	while (a && ro < 0)
	{
		ro = issort(a);
		if (ro >= 0)
			break ;
		if (a->top->next && NUM(a->top) > NUM(a->top->next))
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

void	sortb(t_stack *b, t_stack *a)
{
	int		ro;

	ro = -1;
	while (b && ro < 0)
	{
		ro = issortr(b);
		if (b->top->next && NUM(b->top) < NUM(b->top->next))
		{
			sb(a, b);
			ft_printf("sb\n");
		}
		else
		{
			pa(a, b);
			ft_printf("pa\n");
			if (issort(a))
				sorta(a, b);
		}
	}
	if (ro > 0)
		rot(b, ro, 'b');
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = ft_stack_init();
	b = ft_stack_init();
	if (get_stack(a, argv, argc - 1))
	{
		while (issort(a) || b->top)
		{
			sorta(a, b);
			sortb(b, a);
		}
	}
	else
		ft_printf("Error\n");
	ft_stack_del(&a, free);
	ft_stack_del(&b, free);
	return (0);
}