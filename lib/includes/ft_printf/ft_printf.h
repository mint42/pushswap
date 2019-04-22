/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:16:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:37:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "tsub.h"
# include <stddef.h>
# include <stdarg.h>

/*
** flag bits:                                  ^- 0+ #
** type bits:  lLhH jzgG eEfF cCsS dDiI bBoO uUxX pP%(
*/

# define VALID_FMTS "gGeEfFcCsSpPdDiIbBoOuUxX%lLhHjz1234567890.+- #*()"

char				*clean(char *s, t_sub sub, char **fmt, size_t *slen);
int					ft_printf(const char *fmt, ...);
int					ft_sprintf(char **s, const char *fmt, ...);
int					ft_printfd(int fd, const char *fmt, ...);

#endif
