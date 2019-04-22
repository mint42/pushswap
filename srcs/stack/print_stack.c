/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:23:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 02:40:13 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_snode		*cur;

	if (!stack || !(stack->top))
		return ;
	cur = stack->top;
	ft_printf("top -> ");
	while (cur)
	{
		ft_printf("%d ", (int)cur->content);
		cur = cur->next;
	}
	ft_printf("<- bottom\n");
}
