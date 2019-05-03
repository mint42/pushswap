/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 04:22:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 04:23:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTIONSORT_H
# define INSERTIONSORT_H

typedef struct s_stack		t_stack;

int		insertionsort_a(t_stack *a, t_stack *b, int len_a, int len_b);
int		insertionsort_b(t_stack *a, t_stack *b, int len_a, int len_b);

#endif
