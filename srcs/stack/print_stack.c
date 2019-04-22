/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:23:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/22 06:03:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_snode		*cur;

	ft_printf("top -> ");
	if (!stack || !(stack->top))
	{
		ft_printf("\n");
		return ;
	}
	cur = stack->top;
	while (cur)
	{
		ft_printf("%d ", NUM(cur));
		cur = cur->next;
	}
	ft_printf("<- bottom\n");
}
