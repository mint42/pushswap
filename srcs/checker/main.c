/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:21 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 22:53:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//	fills a linked list with numbers after checking that it's valid

int		fill_stack(t_stack **stack, char *argv, int argc)
{
	int		i;
	long	n;
	int		sign;

	while (argc)
	{
		n = 0;
		i = 0;
		sign = (argv[argc][i] == '-') ? -1 : 1;
		while (argv[argc][i] && ft_isdigit(argv[argc][i]))
		{
			n = n * 10 + (argv[argc][i] - 48);
			++i;
		}
		while (cur)
		{
			if (cur->n
		}
		if (dupicates || argv[argc][i] || n > 2147483647 || n < -2147483648)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		push(&stack, ft_atoi(argv[argc]));
		--argc;
	}
	return (1);
}

//	fills a linked list with instructions after checking that it's valid

int		fill_instructions(t_list **instructions)
{
	while (get_next_line(0, (char *)cur->data)
	{
		cur->size = ft_strlen((char *)cur->data);
		cur = cur->next;
		cur->next = NULL;
	}
	return (0);
}

//	runs the instructions on stacks a and b

void	execute(t_stack **a, t_stack *b, t_list *instructions)
{
	
}

//	checks if stack a is sorted and stack b is empty

void	check(t_stack *a, t_stack *b)
{

}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*instructions;
	t_list		*cur;

	a = NULL;
	b = NULL;
	instructions = ft_lstnew(instructions, 0);
	cur = instructions;
	if (!fill_stack(&a, argc - 1) || !fill_instructions(&instructions))
		return (0);
	execute(a, b, instructions);
	ft_printf("%s\n", check(a, b));
	display(a);
	return (0);
}

//	getting the numbers to put into the linked list
//	first arg at top of stack
//	reading from stdin will give instructions, can use gnl!
//	keep instructions in a double char array?
//	return if instructions are bad but do them if good
//	check if list is sorted 
//	write errors to the stderr, or else display OK\n or KO\n
