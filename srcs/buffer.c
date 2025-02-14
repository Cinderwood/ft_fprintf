/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:56:19 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/12/12 21:53:46 by wsunwoo          ###   ########.fr       */
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

void	buffer_push_str(char buffer[BUFSIZ], char *str)
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
