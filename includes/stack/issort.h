/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 04:08:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 09:12:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISSORT_H
# define ISSORT_H

typedef struct s_stack		t_stack;

int		issort(t_stack *stack, int len);
int		issortr(t_stack *stack, int len);

#endif
