/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 02:25:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define STACK_A (1)
# define STACK_B (2)

typedef struct s_stack		t_stack;

int		find_pivot(t_stack *stack, int len, int aorb);
void	sort_a(t_stack *a, t_stack *b, int half);

#endif
