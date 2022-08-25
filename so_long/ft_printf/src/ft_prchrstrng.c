/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prchrstrng.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:26:07 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/21 11:05:31 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	ft_put_string(const char *str)
{
	int	str_size;

	str_size = 0;
	if (str == NULL)
		str_size += ft_put_string("(null)");
	else
	{
		while (str[str_size])
		{
			ft_put_char(str[str_size]);
			str_size++;
		}
	}
	return (str_size);
}
