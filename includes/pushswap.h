/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/05 13:43:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define MAX	2147483647
# define MIN	-2147483648

# include "stack.h"
# include "../libftprintf/includes/ft_printf.h"

//		checker

int		fill_instructions(char **instructions, t_stack *op);
int		fill_stack(t_stack **stack, char **argv, int argc);
void	execute(t_stack **a, t_stack **b, t_stack *op);
char	*check(t_stack *a, t_stack *b);

//		pushswap


#endif
