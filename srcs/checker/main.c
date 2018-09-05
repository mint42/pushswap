/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:21 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/05 13:46:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		fill_instructions(char **instructions, t_stack *op)
{
	int		i;

	i = 0;
	instructions[0] = ft_strdup("sa");
	instructions[1] = ft_strdup("sb");
	instructions[2] = ft_strdup("ra");
	instructions[3] = ft_strdup("rb");
	instructions[4] = ft_strdup("rra");
	instructions[5] = ft_strdup("rrb");
	instructions[6] = ft_strdup("pa");
	instructions[7] = ft_strdup("pb");
	instructions[8] = ft_strdup("ss");
	instructions[9] = ft_strdup("rr");
	instructions[10] = ft_strdup("rrr");
	instructions[11] = NULL;
	while (i < 11 && get_next_line(0, &instructions[11]) && (i = 0) == 0)
	{
		while (i < 11 && !ft_strequ(instructions[11], instructions[i]))
			++i;
		push(&op, i);
		rotate(&op);
		ft_strdel(&instructions[11]);
	}
	return ((i != 11) ? 1 : 0);
}

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

void	execute(t_stack **a, t_stack **b, t_stack *op)
{
	while (op)
	{
		if (op->num == 0 || op->num == 8)
			swap(a);
		if (op->num == 1 || op->num == 8)
			swap(b);
		if (op->num == 2 || op->num == 9)
			rotate(a);
		if (op->num == 3 || op->num == 9)
			rotate(b);
		if (op->num == 4 || op->num == 10)
			rrotate(a);
		if (op->num == 5 || op->num == 10)
			rrotate(b);
		if (op->num == 6)
			push(a, (*b)->num);
		if (op->num == 7)
			push(b, (*a)->num);
		op = op->next;
	}
}

char	*check(t_stack *a, t_stack *b)
{
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return ("KO\n");
		a = a->next;
	}
	return ((b == NULL) ? "OK\n" : "KO\n");
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*op;
	char		**instructions;

	a = NULL;
	b = NULL;
	op = NULL;
	instructions = (char **)ft_memalloc(sizeof(char *) * 12);
	if (fill_stack(&a, argv, argc - 1) && fill_instructions(instructions, op))
	{
		execute(&a, &b, op);
		write(1, check(a, b), 3);
	}
	else
		write(2, "Error\n", 6);
	stackdel(&a);
	stackdel(&b);
	stackdel(&op);
	return (0);
}
