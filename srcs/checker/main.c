/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:21 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/02 13:01:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		fill_stack(t_stack **stack, int size)
{
	while (argc--)
		push(&a, ft_atoi(argv[argc]));
	return (0);
}

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

void	execute(t_stack **a, t_stack *b, t_list *instructions)
{
	
}

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
	if (!fill_stack(&a, argc) || !fill_instructions(&instructions))
		return (0);
	execute(a, b, instructions);
	ft_printf("%s\n", check(a));
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
