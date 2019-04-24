/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/24 07:50:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define A (1)
# define B (2)

typedef struct s_stack		t_stack;

int		find_pivot(t_stack *stack, int len);
void	sort_a(t_stack *a, t_stack *b, int half);
void	sort_b(t_stack *b, t_stack *a, int half);

#endif
