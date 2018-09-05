/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/04 23:21:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define MAX	2147483647
# define MIN	-2147483648

# include "stack.h"
# include "../libftprintf/includes/ft_printf.h"

//		checker

int		fill_stack(t_stack **stack, char **argv, int argc);
int		execute(t_stack **a, t_stack **b);
char	*check(t_stack *a, t_stack *b);

//		pushswap


#endif
