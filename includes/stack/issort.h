/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:08:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 06:17:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSORT_H
# define ISSORT_H

# include "ft_stack.h"

int		issort(t_stack *stack, int len);
int		issortr(t_stack *stack, int len);
int		ro_index(t_stack *stack);
int		rro_index(t_stack *stack);

#endif
