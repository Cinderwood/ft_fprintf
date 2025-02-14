/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:30:35 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:13:03 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

size_t	parse_precision(const char *ptr, t_obj *obj)
{
	size_t	bytes_read;

	bytes_read = 0;
	if (ptr[bytes_read] == '.')
	{
		obj->precision_true = true;
		bytes_read++;
		obj->precision_num = ft_atoi(ptr + bytes_read);
		while (ft_isdigit(ptr[bytes_read]))
			bytes_read++;
	}
	return (bytes_read);
}
