/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsunwoo <wsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:59:16 by wsunwoo           #+#    #+#             */
/*   Updated: 2024/11/28 21:21:58 by wsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static size_t	get_hex_len(uintptr_t nbr)
{
	size_t	len;

	len = 1;
	while (nbr > 15)
	{
		len += 1;
		nbr /= 16;
	}
	return (len);
}

char	*ptr_to_hex(uintptr_t nbr, int letter_case)
{
	char	*str;
	size_t	len;
	ssize_t	i;

	len = get_hex_len(nbr);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		if (letter_case == 0)
			str[i] = LHEX[nbr % 16];
		else if (letter_case != 0)
			str[i] = UHEX[nbr % 16];
		nbr /= 16;
		i--;
	}
	return (str);
}
