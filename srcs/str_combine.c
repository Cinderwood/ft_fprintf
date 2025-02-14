/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_combine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:16:30 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/11/28 21:21:58 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	str_combine(char **str, ...)
{
	va_list	str_list;
	char	*tmp;

	va_start(str_list, str);
	tmp = va_arg(str_list, char *);
	while (tmp != NULL )
	{
		tmp = ft_strjoin(*str, tmp);
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		free(*str);
		*str = tmp;
		tmp = va_arg(str_list, char *);
	}
	va_end(str_list);
}
