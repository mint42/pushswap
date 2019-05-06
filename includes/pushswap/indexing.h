/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 08:23:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/06 09:12:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEXING_H
# define INDEXING_H

typedef struct s_stack		t_stack;

int		sort_index(t_stack *stack);
int		ro_index(t_stack *stack);
int		rro_index(t_stack *stack);

#endif
