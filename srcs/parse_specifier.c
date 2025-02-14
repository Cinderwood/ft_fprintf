/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:03:36 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/11/28 21:21:58 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	is_specifier(const char c)
{
	if (ft_strchr(VAR_TYPE_LIST, c))
		return (c);
	return (0);
}

size_t	parse_specifier(const char *ptr, t_obj *obj)
{
	size_t	bytes_read;

	bytes_read = 0;
	if (is_specifier(ptr[bytes_read]) != 0)
	{
		obj->var_type = is_specifier(ptr[bytes_read]);
		bytes_read++;
	}
	else
		obj->var_type = 'F';
	return (bytes_read);
}
