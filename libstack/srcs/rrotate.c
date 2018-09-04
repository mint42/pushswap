/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 17:53:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rrotate(t_stack *stack)
{
	t_stack		*temp;

	if (stack == NULL)
		return ;
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	push(&stack, temp->num);
	free(temp);
}
