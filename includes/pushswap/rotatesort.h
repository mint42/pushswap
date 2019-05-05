/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatesort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 05:13:34 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/05 01:28:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATESORT_H
# define ROTATESORT_H

int		rotatesort_a(t_stack *a, int len);
int		rotatesort_b(t_stack *a, t_stack *b, int len, int push_to_a);

#endif
