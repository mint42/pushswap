/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:08:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/07 05:57:06 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "operations.h"
#include "stack.h"
#include "issort.h"
#include "ft_stack.h"
#include "ft_str.h"
#include "ft_mem.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdlib.h>

static int		get_operations(t_stack *ops)
{
	int		*i;
	char	*input;

	if (!ops)
		return (0);
	input = 0;
	while (get_next_line(0, &input))
	{
		i = (int *)ft_memalloc(sizeof(int));
		*i = 0;
		while (g_all_ops[*i])
		{
			if (ft_strequ(input, g_all_ops[*i]))
				break ;
			++(*i);
		}
		ft_stack_push(ops, (void *)i);
		ft_stack_rotate(ops);
		ft_strdel(&input);
		if (*i == TOTAL_OPS)
			return (0);
	}
	return (1);
}

static void		execute(t_stack *a, t_stack *b, t_stack *ops)
{
	t_snode			*cur;
	static void		(*execute_op[TOTAL_OPS + 1])() = {
		pa,
		pb,
		sa,
		sb,
		ss,
		ra,
		rb,
		rr,
		rra,
		rrb,
		rrr,
		0,
	};

	if (!ops || !(ops->top))
		return ;
	cur = ops->top;
	while (cur)
	{
		execute_op[NUM(cur)](a, b, 0);
		cur = cur->next;
	}
}

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*ops;

	a = ft_stack_init();
	b = ft_stack_init();
	ops = ft_stack_init();
	if (get_stack(a, argv, argc - 1) && get_operations(ops))
	{
		execute(a, b, ops);
		if (issort(a, ft_stack_len(a)) && !(b->top))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("Error\n");
	ft_stack_del(&a, ft_stack_del_content);
	ft_stack_del(&b, ft_stack_del_content);
	ft_stack_del(&ops, ft_stack_del_content);
	return (0);
}
