/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:43:38 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 19:46:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	display(t_stack *stack)
{
	t_stack		*temp;

	temp = stack;
	ft_printf("top -> ");
	while (temp != NULL)
	{
		ft_printf("%d, ", temp->num);
		temp = temp->next;
	}
	ft_printf("\n");
}
