/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:02:00 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:36:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREESORT_H
# define THREESORT_H

# include "stack.h"

# define FIRST(stack) NUM((stack)->top)
# define SECOND(stack) NUM((stack)->top->next)
# define THIRD(stack) NUM((stack)->top->next->next)

typedef struct s_stack		t_stack;

int		threesort_a(t_stack *a, int len_a);
int		threesort_b(t_stack *a, t_stack *b, int len_b);
#endif
