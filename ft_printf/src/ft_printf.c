/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:26:13 by fyardimc          #+#    #+#             */
/*   Updated: 2022/07/06 21:34:17 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_findformats(va_list ap1, char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_put_char(va_arg(ap1, int));
	else if (str == 's')
		count += ft_put_string(va_arg(ap1, char *));
	else if (str == 'd' || str == 'i')
		count += ft_put_num_base(va_arg(ap1, int), DEC);
	else if (str == 'x')
		count += ft_put_ux_num(va_arg(ap1, unsigned int), HEX1,
				ft_strlen(HEX1));
	else if (str == 'X')
		count += ft_put_ux_num(va_arg(ap1, unsigned int), HEX2,
				ft_strlen(HEX2));
	else if (str == 'p')
		count += ft_put_ptr(va_arg(ap1, unsigned long long), HEX1,
				ft_strlen(HEX1));
	else if (str == '%')
		count += ft_put_char('%');
	else if (str == 'u')
		count += ft_put_ux_num(va_arg(ap1, unsigned int), DEC, ft_strlen(DEC));
	return (count);
}

int	ft_printf(const char *firstarg, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, firstarg);
	while (*firstarg)
	{
		if (*firstarg == '%')
		{
			count += ft_findformats(ap, *(firstarg + 1));
			firstarg++;
		}
		else
			count += ft_put_char(*firstarg);
		firstarg++;
	}
	va_end(ap);
	return (count);
}
