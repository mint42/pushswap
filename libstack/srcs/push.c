/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:46:34 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/25 06:41:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **stack, int data)
{
	t_stack		*temp;

	if (*stack == NULL)
	{
		*stack = (t_stack *)ft_memalloc(sizeof(t_stack));
		(*stack)->num = data;
		(*stack)->next = NULL;
	}
	else
	{
		temp = (t_stack *)ft_memalloc(sizeof(t_stack));
		temp->num = data;
		temp->next = *stack;
		*stack = temp;
	}
}
