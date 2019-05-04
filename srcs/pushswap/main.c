/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 02:13:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 02:09:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "threesort.h"
#include "insertionsort.h"
#include "quicksort.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>


void		sort_b(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!b || !b->top)
		return ;
//	if (issort(b, stack_len(b)) >= 0)
//		len_b = rotate_b(b, stack_len(a));
	if (len <= 3 && len == ft_stack_len(b))
		len_b = threesort_b(a, b, len);
	else if (len < 33)
		len_b = insertionsort_b(a, b, 0, len);
	else
		len_b = quicksort_b(a, b, len);
	len_a = (len_b) ? len - len_b : 0;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}

void		sort_a(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!a || !a->top)
		return ;
//	if (issortro(a, stack_len(a)) >= 0)
//		len_a = rotate_a(a, stack_len(a));
	if (len <= 3 && len == ft_stack_len(a))
		len_a = threesort_a(a, len);
	else if (len < 33)
		len_a = insertionsort_a(a, b, len, 0);
	else
		len_a = quicksort_a(a, b, len);
	len_b = (len_a) ? len - len_a : 0;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = ft_stack_init();
	b = ft_stack_init();
	if (get_stack(a, argv, argc - 1))
	{
		if (!issort(a, ft_stack_len(a)))
			sort_a(a, b, ft_stack_len(a));
	}
	else
		ft_printf("Error\n");
	ft_stack_del(&a, free);
	ft_stack_del(&b, free);
	return (0);
}
