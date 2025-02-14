/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:15:42 by wsunwoo           #+#    #+#             */
/*   Updated: 2025/02/14 22:22:57 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char	*uitoa(unsigned int nbr)
{
	unsigned int	n;
	size_t			len;
	char			*str;

	n = nbr;
	len = 1;
	while (n > 9)
	{
		len += 1;
		n /= 10;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

static void	print_uint_rules(char *strs[3], t_obj *obj, char *buffer)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (obj->flag_minus == true)
		str_combine(&str, strs[1], strs[0], strs[2], NULL);
	else if (obj->flag_minus == false)
		str_combine(&str, strs[2], strs[1], strs[0], NULL);
	buffer_push_str(buffer, str);
	free(str);
}

size_t	print_uint(t_obj *obj, va_list *ap, char *buffer)
{
	char	*strs[3];
	size_t	bytes_printed;

	strs[0] = uitoa(va_arg(*ap, unsigned int));
	if (!ft_strncmp(strs[0], "0", 2) && obj->precision_true == true \
	&& obj->precision_num == 0)
	{
		free(strs[0]);
		strs[0] = ft_strdup("");
	}
	strs[1] = get_precision_str(obj, ft_strlen(strs[0]));
	strs[2] = get_padding_str(obj, ft_strlen(strs[0]) + ft_strlen(strs[1]));
	print_uint_rules(strs, obj, buffer);
	bytes_printed = ft_strlen(strs[0]) + ft_strlen(strs[1]) \
	+ ft_strlen(strs[2]);
	free(strs[0]);
	free(strs[1]);
	free(strs[2]);
	return (bytes_printed);
}
