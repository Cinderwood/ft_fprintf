/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 03:04:08 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:20:22 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

size_t	print_char(t_obj *obj, va_list *ap, char *buffer)
{
	char	c;
	char	*padding;
	size_t	char_len;
	size_t	bytes_printed;

	c = va_arg(*ap, int);
	char_len = 1;
	obj->flag_zero = false;
	padding = get_padding_str(obj, char_len);
	if (obj->flag_minus == false)
	{
		buffer_push_str(buffer, padding);
		buffer_push_char(buffer, c);
	}
	else if (obj->flag_minus == true)
	{
		buffer_push_char(buffer, c);
		buffer_push_str(buffer, padding);
	}
	bytes_printed = char_len + ft_strlen(padding);
	free(padding);
	return (bytes_printed);
}
