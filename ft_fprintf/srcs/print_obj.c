/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:34:29 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/12/12 19:17:43 by wsunwoo          ###   ########.fr       */
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
		bytes_printed += print_hex(obj, ap, FALSE, buffer);
	if (obj->var_type == 'X')
		bytes_printed += print_hex(obj, ap, TRUE, buffer);
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
	if (obj->flag_hash == TRUE)
		buffer_push_char(buffer, '#');
	if (obj->flag_plus == TRUE)
		buffer_push_char(buffer, '+');
	if (obj->flag_minus == TRUE)
		buffer_push_char(buffer, '-');
	if (obj->width_true == TRUE)
		buffer_push_int(buffer, obj->width_num);
	if (obj->precision_true == TRUE)
	{
		buffer_push_char(buffer, '.');
		buffer_push_int(buffer, obj->precision_num);
	}
	bytes_printed = 0;
	bytes_printed += 1 + obj->flag_hash + obj->flag_plus + obj->flag_minus;
	if (obj->width_true == TRUE)
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
	if (obj->flag_zero == FALSE)
		ft_memset(str, ' ', len);
	else if (obj->flag_zero == TRUE)
		ft_memset(str, '0', len);
	if (obj->precision_true == TRUE || obj->flag_minus == TRUE)
	{
		obj->flag_zero = FALSE;
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
