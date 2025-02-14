/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:03:59 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:21:03 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	*get_int_sign(t_obj *obj, char *str)
{
	if (str[0] == '-')
		return (ft_strdup("-"));
	if (obj->flag_plus == true)
		return (ft_strdup("+"));
	if (obj->flag_space == true)
		return (ft_strdup(" "));
	return (ft_strdup(""));
}

static void	print_int_rules(char *strs[4], t_obj *obj, char *buffer)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (obj->flag_minus == true && obj->flag_zero == true)
		str_combine(&str, strs[1], strs[2], strs[0], strs[3], NULL);
	else if (obj->flag_minus == true && obj->flag_zero == false)
		str_combine(&str, strs[1], strs[2], strs[0], strs[3], NULL);
	else if (obj->flag_minus == false && obj->flag_zero == true)
		str_combine(&str, strs[1], strs[3], strs[2], strs[0], NULL);
	else if (obj->flag_minus == false && obj->flag_zero == false)
		str_combine(&str, strs[3], strs[1], strs[2], strs[0], NULL);
	buffer_push_str(buffer, str);
	free(str);
}

size_t	print_int(t_obj *obj, va_list *ap, char *buffer)
{
	char	*strs[4];
	char	*num;
	size_t	bytes_printed;

	num = ft_itoa(va_arg(*ap, int));
	strs[0] = ft_strtrim(num, "-");
	if (!ft_strncmp(strs[0], "0", 2) && obj->precision_true == true \
	&& obj->precision_num == 0)
	{
		free(strs[0]);
		strs[0] = ft_strdup("");
	}
	strs[1] = get_int_sign(obj, num);
	strs[2] = get_precision_str(obj, ft_strlen(strs[0]));
	strs[3] = get_padding_str(obj, ft_strlen(strs[0]) \
	+ ft_strlen(strs[1]) + ft_strlen(strs[2]));
	print_int_rules(strs, obj, buffer);
	bytes_printed = ft_strlen(strs[0]) + ft_strlen(strs[1]) \
	+ ft_strlen(strs[2]) + ft_strlen(strs[3]);
	free(num);
	free(strs[0]);
	free(strs[1]);
	free(strs[2]);
	free(strs[3]);
	return (bytes_printed);
}
