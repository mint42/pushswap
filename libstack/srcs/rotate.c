/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:50:39 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/05 09:29:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack **stack)
{
	t_stack		*temp;
	t_stack		*new;

	if (stack == NULL)
		return ;
	temp = *stack;
	new = (t_stack *)ft_memalloc(sizeof(t_stack));
	new->num = (*stack)->num;
	new->next = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	temp = (*stack)->next;
	free(stack);
	*stack = temp;
}
