/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:31:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 08:18:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_printf.h"

void	pa(t_stack *a, t_stack *b, int print)
{
	if (!a || !b || !(b->top))
		return ;
	ft_stack_push(a, ft_stack_pop(b));
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b, int print)
{
	if (!a || !b || !(a->top))
		return ;
	ft_stack_push(b, ft_stack_pop(a));
	if (print)
		ft_printf("pb\n");
}
