/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 02:13:03 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/25 05:40:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "stack.h"
#include "ft_stack.h"
#include "ft_printf.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = ft_stack_init();
	b = ft_stack_init();
	if (get_stack(a, argv, argc - 1))
	{
		if (issort(a) != 0)
			sort_a(a, b, stack_len(a));
	}
	else
		ft_printf("Error\n");
	ft_printf("finished\n");
	print_stack(a);
	print_stack(b);
	ft_stack_del(&a, free);
	ft_stack_del(&b, free);
	return (0);
}
