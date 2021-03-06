/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 05:48:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 05:11:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_stack.h"

# define NUM(snode) (*((int *)(snode->content)))

int			get_stack(t_stack *stack, char **argv, int argc);
void		print_stack(t_stack *stack, int len);

#endif
