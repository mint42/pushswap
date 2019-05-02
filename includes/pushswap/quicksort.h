/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:13:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/02 02:30:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

typedef struct s_stack		t_stack;

int				quicksort_a(t_stack *a, t_stack *b, int len_a);
int				quicksort_b(t_stack *a, t_stack *b, int len_b);

#endif
