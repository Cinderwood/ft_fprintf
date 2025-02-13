/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:33 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/12/12 21:53:11 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static t_obj	*create_obj(void)
{
	t_obj	*obj;

	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	return (obj);
}

static size_t	start_parse(const char *format, va_list *ap, \
size_t *bytes_printed, char *buffer)
{
	t_obj	*obj;
	size_t	bytes_read;

	obj = create_obj();
	if (obj == NULL)
		exit (EXIT_FAILURE);
	bytes_read = parse_obj_wrapper(format, obj);
	if (obj->var_type == 'F')
		*bytes_printed += print_failed_obj(obj, buffer);
	else
		*bytes_printed += print_obj(obj, ap, buffer);
	free(obj);
	return (bytes_read);
}

int	ft_fprintf(int stream, const char *format, ...)
{
	va_list		ap;
	size_t		bytes_read;
	size_t		bytes_printed;
	static char	buffer[BUFSIZ] = {0};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	bytes_read = 0;
	bytes_printed = 0;
	while (format[bytes_read] != '\0')
	{
		if (format[bytes_read] == '%')
		{
			bytes_read += start_parse(format + bytes_read, &ap, \
			&bytes_printed, buffer);
			continue ;
		}
		buffer_push_char(buffer, format[bytes_read]);
		bytes_read++;
		bytes_printed++;
	}
	va_end(ap);
	buffer_flush(buffer, stream);
	return (bytes_printed);
}
