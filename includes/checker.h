/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:59:13 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/27 10:01:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "../libftprintf/includes/ft_printf.h"

void	execute(t_stack **a, t_stack **b, t_stack *op);
int		fill_instructions(char **instructions, t_stack **op);

#endif
