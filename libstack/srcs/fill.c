/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 07:59:47 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/25 08:13:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
