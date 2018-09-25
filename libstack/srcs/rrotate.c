/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/07 19:57:05 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rrotate(t_stack **stack)
{
	t_stack		*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	printf("testy\n");
	push(&temp, (*stack)->next->num);
	printf("testy\n");
	free(*stack);
	*stack = temp;
}
