/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:05:21 by rreedy            #+#    #+#             */
/*   Updated: 2018/08/31 10:12:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

//Swap (sa, sb, ss)
//swap first 2 elements on stack

void	swap(t_stack *stack)
{
	int		temp;

	temp = stack->next;
	stack->next = stack;
	stack = temp;
}

//Push (pa, pb)
//put top of b onto top of a or vice versa

void	push(t_stack *stack, int data)
{
	t_stack		temp;

	if (stack == NULL)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		stack->num = data;
		stack->next = NULL;
	}
	else
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		temp->num = data;
		temp->next = stack;
		stack = temp;
	}
}

//Rotate (ra, rb, rr)
//shift all elements up on stack by one (first becomes last)

void	rotate(t_stack *stack)
{
	t_stack		temp;
	t_stack		new;

	if (stack == NULL)
		return ;
	temp = stack;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->num = stack->num;
	new->next = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	temp = stack->next;
	free(stack);
	stack = temp;
}

//Reverse Rotate (rra, rrb, rrr)
//shift all elements down on stack by one (last becomes first)

void	rrotate(t_stack *stack)
{
	t_stack		temp;

	if (stack == NULL)
		return ;
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	push(stack, temp->data);
	free(temp);
}

void	display(t_stack *stack)
{
	t_stack		temp;

	temp = stack;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->num);
		temp = temp->next;
	}
	ft_printf("_\na\n");
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	i = argc - 1;
	while (i--)
	{
		ft_printf("stack numbers: %d\n", argv[i]);
		push(a, argv[i]);
		display(a);
	}


//	getting the numbers to put into the linked list
//	first arg at top of stack
//	reading from stdin will give instructions, can use gnl!
//	keep instructions in a double char array?
//	return if instructions are bad but do them if good
//	check if list is sorted 
//	write errors to the stderr, or else display OK\n or KO\n
	return (0);
}
