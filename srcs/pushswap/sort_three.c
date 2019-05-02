/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_THIRD(a).c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:51:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 04:15:50 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort_three.h"
#include "pushswap.h"
#include "ft_stack.h"
#include "ft_printf.h"

int		sort_three(t_stack *a, int len)
{
	if (len == 1)
		return (0);
	if (len == 2 && FIRST(a) > SECOND(a))
		sa(a, 0, 1);
	if (len == 2)
		return (0);
	if (FIRST(a) < SECOND(a) && FIRST(a) < THIRD(a) && SECOND(a) > THIRD(a))
	{
		sa(a, 0, 1);
		ra(a, 0, 1);
	}
	if (FIRST(a) > SECOND(a) && FIRST(a) < THIRD(a) && SECOND(a) < THIRD(a))
		sa(a, 0, 1);
	if (FIRST(a) < SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) > THIRD(a))
		rra(a, 0, 1);
	if (FIRST(a) > SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) < THIRD(a))
		ra(a, 0, 1);
	if (FIRST(a) > SECOND(a) && FIRST(a) > THIRD(a) && SECOND(a) > THIRD(a))
	{
		sa(a, 0, 1);
		rra(a, 0, 1);
	}
	return (0);
}
