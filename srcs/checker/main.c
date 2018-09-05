/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:21 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/04 23:30:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		fill_stack(t_stack **stack, char **argv, int argc)
{
	int			i;
	long		n;
	t_stack		*cur;

	while (argc)
	{
		n = 0;
		i = 0;
		cur = *stack;
		while (argv[argc][i] && ft_isdigit(argv[argc][i]))
			n = n * 10 + (argv[argc][i++] - 48);
		if (argv[argc][0] == '-')
			n = n * -1;
		if (i == 0 || argv[argc][i] || n > MAX || n < MIN)
			return (0);
		while (cur)
		{
			if (cur->num == n)
				return (0);
			cur = cur->next;
		}
		push(stack, ft_atoi(argv[argc]));
		--argc;
	}
	return (1);
}

int		execute(t_stack **a, t_stack **b)
{
	char	*op;
	int		er;

	op = NULL;
	er = 0;
	while (get_next_line(0, &op) && !er)
	{
		er = 1;
		if ((ft_strequ(op, "sa") || ft_strequ(op, "ss")) && er = 0)
			swap(a);
		if ((ft_strequ(op, "sb") || ft_strequ(op, "ss")) && er = 0)
			swap(b);
		if ((ft_strequ(op, "ra") || ft_strequ(op, "rr")) && er = 0)
			rotate(a);
		if ((ft_strequ(op, "rb") || ft_strequ(op, "rr")) && er = 0)
			rotate(b);
		if ((ft_strequ(op, "rra") || ft_strequ(op, "rrr")) && er = 0)
			rrotate(a);
		if ((ft_strequ(op, "rrb") || ft_strequ(op, "rrr")) && er = 0)
			rrotate(b);
		if (ft_strequ(op, "pa") && er = 0)
			push(a, *(b->num));
		if (ft_strequ(op, "pb") && er = 0)
			push(b, *(a->num));
		free(&op);
	}
	return (er);
}

char	*check(t_stack *a, t_stack *b)
{
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return ("KO");
		a = a->next;
	}
	return ((b == NULL) ? "OK" : "KO");
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (fill_stack(&a, argv, argc - 1) && execute(&a, &b))
		write(1, check(a, b), 2);
	else
		write(2, "Error\n", 6);
	stackdel(&a);
	stackdel(&b);
	return (0);
}
