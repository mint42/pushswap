/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:08:22 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:53:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		fill_instructions(char **instructions, t_stack **op)
{
	int		i;
	char	*s;

	i = 0;
	s = ft_strnew(0);
	instructions[0] = "sa";
	instructions[1] = "sb";
	instructions[2] = "ra";
	instructions[3] = "rb";
	instructions[4] = "rra";
	instructions[5] = "rrb";
	instructions[6] = "pa";
	instructions[7] = "pb";
	instructions[8] = "ss";
	instructions[9] = "rr";
	instructions[10] = "rrr";
	while (i < 11 && get_next_line(0, &s) && (i = 0) == 0)
	{
		while (i < 11 && !ft_strequ(s, instructions[i]))
			++i;
		push(op, i);
		rotate(op);
		ft_strdel(&s);
	}
	return ((i != 11) ? 1 : 0);
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
			push(a, (pop(b)).num);
		if (op->num == 7)
			push(b, (pop(a)).num);
		op = op->next;
	}
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
	if (fill_stack(&a, argv, argc - 1) && fill_instructions(instructions, &op))
	{
		execute(&a, &b, op);
		if ((issort(a) == 0) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	stackdel(&a);
	stackdel(&b);
	stackdel(&op);
	return (0);
}
