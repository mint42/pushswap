/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/02 11:55:50 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libftprintf/includes/ft_printf.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void	display(t_stack *stack);
void	push(t_stack **stack, int data);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
void	swap(t_stack **stack);

#endif
