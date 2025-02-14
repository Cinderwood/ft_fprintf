/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:31:57 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/11/28 21:22:22 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

size_t	parse_obj_wrapper(const char *ptr, t_obj *obj)
{
	size_t	bytes_read;

	bytes_read = 1;
	bytes_read += parse_flags(ptr + bytes_read, obj);
	bytes_read += parse_width(ptr + bytes_read, obj);
	bytes_read += parse_precision(ptr + bytes_read, obj);
	bytes_read += parse_specifier(ptr + bytes_read, obj);
	return (bytes_read);
}
