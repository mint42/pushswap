/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:47:42 by rreedy            #+#    #+#             */
/*   Updated: 2018/10/04 10:19:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rot(t_stack **stack, int ro, char aorb)
{
	int		rro;

	rro = 0;
	if (ro > (stacklen(*stack) / 2))
		rro = stacklen(*stack) - ro;
	while (!rro && ro)
	{
		rotate(stack);
		ft_printf("r%c\n", aorb);
		--ro;
	}
	while (rro)
	{
		rrotate(stack);
		ft_printf("rr%c\n", aorb);
		--rro;
	}
}

void	sorta(t_stack **a, t_stack **b)
{
	int		ro;

	ro = -1;
	while (*a && ro < 0)
	{
		ro = issort(*a);
		if (ro >= 0)
			break ;
		if ((*a)->next && (*a)->num > (*a)->next->num)
		{
			swap(a);
			ft_printf("sa\n");
		}
		else
		{
			push(b, (pop(a)).num);
			ft_printf("pb\n");
		}
	}
	if (ro > 0)
		rot(a, ro, 'a');
}

void	sortb(t_stack **b, t_stack **a)
{
	int		ro;

	ro = -1;
	while (*b && ro < 0)
	{
		ro = issortr(*b);
		if ((*b)->next && (*b)->num < (*b)->next->num)
		{
			swap(b);
			ft_printf("sb\n");
		}
		else
		{
			push(a, (pop(b)).num);
			ft_printf("pa\n");
			if (issort(*a))
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

	a = NULL;
	b = NULL;
	if (fill_stack(&a, argv, argc - 1))
	{
		while (issort(a) || b)
		{
			sorta(&a, &b);
			sortb(&b, &a);
		}
	}
	else
		write(2, "Error\n", 6);
	stackdel(&a);
	stackdel(&b);
	return (0);
}
