/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:20:45 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/07 04:30:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_mem.h"
#include "ft_stack.h"
#include "ft_utils.h"
#include <limits.h>

static int		is_atol(long int *n, const char *s)
{
	int		sign;

	sign = 1;
	if (!s)
		return (1);
	if (*s == '+')
		++s;
	else if (*s == '-')
	{
		sign = -1;
		++s;
	}
	if (!ft_isdigit(*s))
		return (1);
	while (*s && ft_isdigit(*s))
	{
		*n = (*n * 10) + (*s - 48);
		++s;
		if ((*n - 1) > INT_MAX)
			return (1);
	}
	*n = *n * sign;
	if (*n > INT_MAX || *n < INT_MIN)
		return (1);
	return ((*s == '\0') ? 0 : 1);
}

static int		is_duplicate(t_stack *stack, int n)
{
	t_snode		*dup;

	dup = stack->top;
	while (dup)
	{
		if (NUM(dup) == n)
			return (1);
		dup = dup->next;
	}
	return (0);
}

int				get_stack(t_stack *stack, char **argv, int argc)
{
	long int	*n;

	if (!stack)
		return (0);
	while (argc >= 1)
	{
		n = (long int *)ft_memalloc(sizeof(long int));
		*n = 0;
		if (is_atol(n, argv[argc]) || is_duplicate(stack, *n))
			return (0);
		ft_stack_push(stack, (void *)n);
		--argc;
	}
	return (1);
}
