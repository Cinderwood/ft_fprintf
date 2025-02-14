/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 03:06:10 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/12/12 17:58:32 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	print_str_rules(t_obj *obj, char *strs[3], char *buffer)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (obj->flag_minus == FALSE)
		str_combine(&str, strs[2], strs[1], NULL);
	else if (obj->flag_minus == TRUE)
		str_combine(&str, strs[1], strs[2], NULL);
	buffer_push_str(buffer, str);
	free(str);
}

size_t	print_str(t_obj *obj, va_list *ap, char *buffer)
{
	char	*strs[3];
	size_t	bytes_printed;

	strs[0] = va_arg(*ap, char *);
	if (strs[0] == NULL)
	{
		if (obj->precision_true == TRUE && obj->precision_num < 6)
			strs[1] = ft_strdup("");
		else
			strs[1] = ft_strdup("(null)");
	}
	else
	{
		if (obj->precision_true == TRUE)
			strs[1] = ft_substr(strs[0], 0, obj->precision_num);
		else
			strs[1] = ft_strdup(strs[0]);
	}
	obj->flag_zero = FALSE;
	strs[2] = get_padding_str(obj, ft_strlen(strs[1]));
	print_str_rules(obj, strs, buffer);
	bytes_printed = ft_strlen(strs[1]) + ft_strlen(strs[2]);
	free(strs[1]);
	free(strs[2]);
	return (bytes_printed);
}
