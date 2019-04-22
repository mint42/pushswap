/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:31:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 05:33:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !(a->top) || !(b->top))
		return ;
	ft_stack_push(a, ft_stack_pop(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !(a->top) || !(b->top))
		return ;
	ft_stack_push(b, ft_stack_pop(a));
}
