/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:30:33 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/05 09:04:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libftprintf/includes/ft_printf.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void	display(t_stack *stack);
void	*peek(t_stack *stack);
void	*pop(t_stack **stack);
void	push(t_stack **stack, int data);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
void	stackdel(t_stack **stack);
void	swap(t_stack **stack);

#endif
