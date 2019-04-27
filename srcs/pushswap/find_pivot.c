/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 07:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/26 21:26:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include <unistd.h>
#include <fcntl.h>

int			get_pivot(t_stack *stack, int index)
{
	t_snode		*cur;
	int			i;

	i = 0;
	cur = stack->top;
	while (cur && i < index)
	{
		cur = cur->next;
		++i;
	}
	if (cur)
		return (NUM(cur));
	else
		return (-1);
}

int			get_index(int fd, int len)
{
	size_t	buf;
	int		nbytes;

	nbytes = 8;
	if (read(fd, (void *)&buf, nbytes) != nbytes)
		return (-1);
	return (buf % len);
}

int			find_pivot(t_stack *stack, int len, int aorb)
{
	int			pivot;
	int			fd;
	int			index;

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
	index = get_index(fd, len);
	if (index == -1)
		return (-1);
	pivot = get_pivot(stack, index);
	close(fd);
	return (pivot);
}
