/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 07:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/28 03:09:32 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include <unistd.h>
#include <fcntl.h>


static int			get_random_pivot(t_stack *stack, int fd, int len)
{
	t_snode		*cur;
	size_t		buf;
	int			nbytes;
	int			i;

	nbytes = 8;
	if (read(fd, (void *)&buf, nbytes) != nbytes)
		return (-1);
	i = buf % len;
	cur = stack->top;
	while (cur && i)
	{
		cur = cur->next;
		--i;
	}
	if (cur)
		return (NUM(cur));
	else
		return (-1);
}

static int			get_pivot(t_stack *stack, int fd, int len)
{
	int			one;
	int			two;
	int			three;

	one = 0;
	two = 0;
	three = 0;
	while (one == two || one == three || two == three)
	{
		one = get_random_pivot(stack, fd, len);
		two = get_random_pivot(stack, fd, len);
		three = get_random_pivot(stack, fd, len);
		if (one == -1 || two == -1 || three == -1)
			return (-1);
	}
	if ((two < one && one < three) || (three < one && one < two))
		return (one);
	if ((one < two && two < three) || (three < two && two < one))
		return (two);
	return (three);
}

int			find_pivot(t_stack *stack, int len, int aorb)
{
	int			pivot;
	int			fd;

	if (!stack || !(stack->top) || !len)
		return (-1);
	if (len == 2)
	{
		if ((aorb == A && NUM(stack->top) < NUM(stack->top->next)) ||
				(aorb == B && (NUM(stack->top) > NUM(stack->top->next))))
			return (NUM(stack->top));
		else
			return (NUM(stack->top->next));
	}
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (-1);
	pivot = get_pivot(stack, fd, len);
	close(fd);
	return (pivot);
}
