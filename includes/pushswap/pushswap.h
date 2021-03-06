/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:16:20 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 04:26:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_stack		t_stack;

void	sort_a(t_stack *a, t_stack *b, int len);
void	sort_b(t_stack *a, t_stack *b, int len);

#endif
