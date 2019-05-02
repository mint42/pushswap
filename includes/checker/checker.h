/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:59:13 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/21 05:52:20 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define TOTAL_OPS (11)

static const char	*g_all_ops[TOTAL_OPS + 1] =
{
	"pa",
	"pb",
	"sa",
	"sb",
	"ss",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	0,
};

#endif
