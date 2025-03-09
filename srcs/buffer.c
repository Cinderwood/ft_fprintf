/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:56:19 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/10 03:03:01 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	buffer_flush(char buffer[BUFSIZ], int stream)
{
	size_t	buff_len;

	buff_len = ft_strlen(buffer);
	if (buff_len > 0)
		write(stream, buffer, buff_len);
	ft_bzero(buffer, BUFSIZ);
}

void	buffer_push_char(char buffer[BUFSIZ], char c)
{
	size_t		buff_len;

	if (c == '\0')
	{
		ft_putstr_fd("ft_fprintf: attempting to push ('\0') to buffer", \
		STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	buff_len = ft_strlen(buffer);
	if (buff_len >= BUFSIZ)
	{
		ft_putstr_fd("ft_fprintf: buffer overflow exception", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	buffer[buff_len] = c;
}

void	buffer_push_str(char buffer[BUFSIZ], const char *str)
{
	size_t		buff_len;
	size_t		index;

	if (str == NULL)
	{
		ft_putstr_fd("ft_fprintf: attempting to push null to buffer", \
		STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	buff_len = ft_strlen(buffer);
	index = 0;
	while (str[index] != '\0')
	{
		if (buff_len + index >= BUFSIZ)
		{
			ft_putstr_fd("ft_fprintf: buffer overflow exception", \
			STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		buffer[buff_len + index] = str[index];
		index++;
	}
}

void	buffer_push_int(char buffer[BUFSIZ], int nbr)
{
	size_t		buff_len;
	size_t		index;
	char		*tmp;

	tmp = ft_itoa(nbr);
	if (tmp == NULL)
	{
		ft_putstr_fd("ft_fprintf: itoa malloc error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	buff_len = ft_strlen(buffer);
	index = 0;
	while (tmp[index] != '\0')
	{
		if (buff_len + index >= BUFSIZ)
		{
			ft_putstr_fd("ft_fprintf: buffer overflow exception", \
			STDERR_FILENO);
			free(tmp);
			exit(EXIT_FAILURE);
		}
		buffer[buff_len + index] = tmp[index];
		index++;
	}
	free(tmp);
}

size_t	buffer_push_va_list(char buffer[BUFSIZ], const char *format, va_list ap)
{
	size_t	bytes_read;
	size_t	bytes_printed;
	va_list	ap_copy;

	bytes_read = 0;
	bytes_printed = 0;
	va_copy(ap_copy, ap);
	while (format[bytes_read] != '\0')
	{
		if (format[bytes_read] == '%')
		{
			bytes_read += start_parse(format + bytes_read, &ap_copy, \
			&bytes_printed, buffer);
			continue ;
		}
		buffer_push_char(buffer, format[bytes_read]);
		bytes_read++;
		bytes_printed++;
	}
	va_end(ap_copy);
	return (bytes_printed);
}
