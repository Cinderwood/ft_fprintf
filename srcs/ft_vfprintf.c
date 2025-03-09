/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:14:16 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/10 03:12:18 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_vfprintf(int stream, const char *format, va_list	ap)
{
	char	buffer[BUFSIZ];
	size_t	bytes_printed;

	ft_bzero(buffer, BUFSIZ);
	bytes_printed = buffer_push_va_list(buffer, format, ap);
	buffer_flush(buffer, stream);
	return (bytes_printed);
}

size_t	start_parse(const char *format, va_list *ap, size_t *bytes_printed, \
char *buffer)
{
	t_obj	*obj;
	size_t	bytes_read;

	obj = create_obj();
	if (obj == NULL)
	{
		ft_putstr_fd("ft_printf: malloc failed\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	bytes_read = parse_obj_wrapper(format, obj);
	if (obj->var_type == 'F')
		*bytes_printed += print_failed_obj(obj, buffer);
	else
		*bytes_printed += print_obj(obj, ap, buffer);
	free(obj);
	return (bytes_read);
}

t_obj	*create_obj(void)
{
	t_obj	*obj;

	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	return (obj);
}
