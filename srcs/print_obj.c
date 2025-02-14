/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:34:29 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:22:08 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

size_t	print_obj(t_obj *obj, va_list *ap, char *buffer)
{
	size_t	bytes_printed;

	bytes_printed = 0;
	if (obj->var_type == 'c')
		bytes_printed += print_char(obj, ap, buffer);
	if (obj->var_type == 's')
		bytes_printed += print_str(obj, ap, buffer);
	if (obj->var_type == 'p')
		bytes_printed += print_ptr(obj, ap, buffer);
	if (obj->var_type == 'd' || obj->var_type == 'i')
		bytes_printed += print_int(obj, ap, buffer);
	if (obj->var_type == 'u')
		bytes_printed += print_uint(obj, ap, buffer);
	if (obj->var_type == 'x')
		bytes_printed += print_hex(obj, ap, false, buffer);
	if (obj->var_type == 'X')
		bytes_printed += print_hex(obj, ap, true, buffer);
	if (obj->var_type == '%')
	{
		buffer_push_char(buffer, '%');
		bytes_printed += 1;
	}
	return (bytes_printed);
}

static	size_t	get_int_len(int nbr)
{
	size_t	n;

	n = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

size_t	print_failed_obj(t_obj *obj, char *buffer)
{
	size_t	bytes_printed;

	buffer_push_char(buffer, '%');
	if (obj->flag_hash == true)
		buffer_push_char(buffer, '#');
	if (obj->flag_plus == true)
		buffer_push_char(buffer, '+');
	if (obj->flag_minus == true)
		buffer_push_char(buffer, '-');
	if (obj->width_true == true)
		buffer_push_int(buffer, obj->width_num);
	if (obj->precision_true == true)
	{
		buffer_push_char(buffer, '.');
		buffer_push_int(buffer, obj->precision_num);
	}
	bytes_printed = 0;
	bytes_printed += 1 + obj->flag_hash + obj->flag_plus + obj->flag_minus;
	if (obj->width_true == true)
		bytes_printed += get_int_len(obj->width_num);
	if (obj->precision_true)
		bytes_printed += get_int_len(obj->precision_num) + 1;
	return (bytes_printed);
}

char	*get_padding_str(t_obj *obj, size_t var_len)
{
	char	*str;
	ssize_t	len;

	len = obj->width_num - var_len;
	if (len < 0)
		len = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (obj->flag_zero == false)
		ft_memset(str, ' ', len);
	else if (obj->flag_zero == true)
		ft_memset(str, '0', len);
	if (obj->precision_true == true || obj->flag_minus == true)
	{
		obj->flag_zero = false;
		ft_memset(str, ' ', len);
	}
	return (str);
}

char	*get_precision_str(t_obj *obj, size_t var_len)
{
	char	*str;
	ssize_t	len;

	len = obj->precision_num - var_len;
	if (len < 0)
		len = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '0', len);
	return (str);
}
