/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:56:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 04:17:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_THREE_H
# define SORT_THREE_H

# include "stack.h"

# define FIRST(stack) NUM((stack)->top)
# define SECOND(stack) NUM((stack)->top->next)
# define THIRD(stack) NUM((stack)->top->next->next)

typedef struct s_stack		t_stack;

int		sort_three(t_stack *a, int len);
#endif
