/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:47:42 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/25 10:58:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorta(t_stack **a, t_stack **b)
{
	while (*a)
	{
		if ((*a)->next && (*a)->num > (*a)->next->num)
		{
			swap(a);
			ft_printf("sa\n");
			if (issort(*a))
				break ;
		}
		else
		{
			push(b, (pop(a)).num);
			ft_printf("pb\n");
		}
	}
}

void	sortb(t_stack **b, t_stack **a)
{
	while (*b)
	{
		if ((*b)->next && (*b)->num < (*b)->next->num)
		{
			swap(b);
			ft_printf("sb\n");
		}
		else
		{
			push(a, (pop(b)).num);
			ft_printf("pa\n");
			if (!issort(*a))
				sorta(a, b);
		}
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (fill_stack(&a, argv, argc - 1))
	{
		while (!issort(a) || b)
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
