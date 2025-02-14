/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:13:12 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:19:59 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

size_t	parse_width(const char *ptr, t_obj *obj)
{
	size_t	bytes_read;

	bytes_read = 0;
	while (ft_isdigit(ptr[bytes_read]))
		bytes_read++;
	if (bytes_read != 0)
	{
		obj->width_true = true;
		obj->width_num = ft_atoi(ptr);
	}
	return (bytes_read);
}
