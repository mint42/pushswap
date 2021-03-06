/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:23:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/25 09:07:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack, int len)
{
	t_snode		*cur;

	ft_printf("top -> ");
	if (!stack || !(stack->top))
	{
		ft_printf("\n");
		return ;
	}
	cur = stack->top;
	while (cur && len)
	{
		ft_printf("%d ", NUM(cur));
		cur = cur->next;
		--len;
	}
	ft_printf("<- bottom\n");
}
