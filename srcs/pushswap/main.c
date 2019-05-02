/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 02:13:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 06:35:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "sort_three.h"
#include "quicksort.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>


static void		sort_b(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!b || !b->top)
		return ;
	if (issort(b, stack_len(b)) >= 0)
		len_b = rotate_b(b, stack_len(a));
	else if (issort(b, len) == 0)
		len_b = rotate_b(b, len);
	else if (len <= 3 && stack_len(b) <= 3)
		len_b = threesort_b(b, len);
	else if (!42)
		len_b = bubblesort_b(b, len);
	else
		len_b = quicksort_b(a, b, len);
	len_a = (len_b) ? len - len_b : 0;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}

void			sort_a(t_stack *a, t_stack *b, int len)
{
	int		len_a;
	int		len_b;

	if (!a || !a->top)
		return ;
	if (issort(a, stack_len(a)) >= 0)
		len_a = rotate_a(a, stack_len(a));
	else if (issort(a, len) == 0)
		len_a = rotate_a(a, len);
	else if (len <= 3 && stack_len(a) <= 3)
		len_a = threesort_a(a, len);
	else if (!42)
		len_a = bubblesort_a(a, len);
	else
		len_a = quicksort_a(a, b, len);
	len_b = (len_a) ? len - len_a : 0;
	if (len_a != 0)
		sort_a(a, b, len_a);
	if (len_b != 0)
		sort_b(a, b, len_b);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = ft_stack_init();
	b = ft_stack_init();
	if (get_stack(a, argv, argc - 1))
		sort_a(a, b, stack_len(a));
	else
		ft_printf("Error\n");
	ft_stack_del(&a, free);
	ft_stack_del(&b, free);
	return (0);
}
