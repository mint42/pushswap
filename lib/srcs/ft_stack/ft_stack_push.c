/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:16:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:42:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_mem.h"

void		ft_stack_push(t_stack *stack, void *content)
{
	t_snode		*node;

	if (!stack)
		return ;
	node = (t_snode *)ft_memalloc(sizeof(t_snode));
	if (!node)
		return ;
	if (!(stack->top))
	{
		node->content = content;
		stack->top = node;
	}
	else
	{
		node->content = stack->top->content;
		node->next = stack->top->next;
		stack->top->next = node->next;
		stack->top->content = content;
	}
}
