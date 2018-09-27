/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:37:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stack.h"
# include "../libftprintf/includes/ft_printf.h"

void	rot(t_stack **stack, int ro, char aorb);
void	sorta(t_stack **a, t_stack **b);
void	sortb(t_stack **b, t_stack **a);

#endif
