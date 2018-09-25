/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:30:33 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/25 11:10:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libftprintf/includes/ft_printf.h"

# define MAX 2147483647
# define MIN -2147483648

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

int					fill_stack(t_stack **stack, char **argv, int argc);
int					issort(t_stack *stack);
int					issortr(t_stack *stack);
void				display(t_stack *stack);
void				push(t_stack **stack, int data);
void				rotate(t_stack **stack);
void				rrotate(t_stack **stack);
void				stackdel(t_stack **stack);
void				swap(t_stack **stack);
t_stack				pop(t_stack **stack);
t_stack				peek(t_stack *stack);

#endif
