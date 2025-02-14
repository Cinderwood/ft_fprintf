/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:38:42 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/11/28 21:22:20 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	is_flag(const char p)
{
	if (p == '-' || p == '0' || p == '#' || p == ' ' || p == '+')
		return (p);
	return (0);
}

size_t	parse_flags(const char *ptr, t_obj *obj)
{
	size_t	bytes_read;

	bytes_read = 0;
	while (is_flag(ptr[bytes_read]) != 0)
	{
		if (is_flag(ptr[bytes_read]) == '-')
			obj->flag_minus = 1;
		if (is_flag(ptr[bytes_read]) == '0')
			obj->flag_zero = 1;
		if (is_flag(ptr[bytes_read]) == '#')
			obj->flag_hash = 1;
		if (is_flag(ptr[bytes_read]) == ' ')
			obj->flag_space = 1;
		if (is_flag(ptr[bytes_read]) == '+')
			obj->flag_plus = 1;
		bytes_read++;
	}
	return (bytes_read);
}
