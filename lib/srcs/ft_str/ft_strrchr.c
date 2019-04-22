/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:18:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:10:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
		if (*s++ == (char)c)
			ptr = (char *)(s - 1);
	return (((char)c == '\0') ? (char *)s : ptr);
}
