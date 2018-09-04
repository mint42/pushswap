/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 17:35:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stack.h"
# include "../libftprintf/includes/ft_printf.h"

//		checker

int		fill_stack(t_stack **stack, char *argv, int argc);
int		fill_instructions(t_list **instructions);
void	execute(t_stack **a, t_stack *b, t_list *instructions);
void	check(t_stack *a, t_stack *b);

//		pushswap


#endif
