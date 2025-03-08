/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:43:33 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/03/07 12:05:05 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		bytes_printed;

	va_start(ap, format);
	bytes_printed = ft_vfprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (bytes_printed);
}

int	ft_fprintf(int stream, const char *format, ...)
{
	va_list		ap;
	size_t		bytes_printed;

	va_start(ap, format);
	bytes_printed = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (bytes_printed);
}
