/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_unum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:26:19 by fyardimc          #+#    #+#             */
/*   Updated: 2022/07/06 21:34:14 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_digit_num(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
		return (11);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static unsigned long long	ft_find_xu_num(unsigned long long num,
											size_t base_len)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

int	ft_put_num_base(int n, const char *base)
{
	int	len;

	len = ft_find_digit_num(n);
	if (n == -2147483648)
	{
		ft_put_char('-');
		ft_put_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_put_char('-');
		n *= -1;
	}
	if (n < 10)
	{
		ft_put_char(base[n % 10]);
		return (len);
	}
	else
		ft_put_num_base(n / 10, base);
	ft_put_num_base(n % 10, base);
	return (len);
}

int	ft_put_ux_num(unsigned long long n, const char *base, size_t base_len)
{
	int	len;

	len = ft_find_xu_num(n, base_len);
	if (n < base_len)
	{
		ft_put_char(base[n % base_len]);
		return (len);
	}
	else
		ft_put_ux_num(n / base_len, base, base_len);
	ft_put_ux_num(n % base_len, base, base_len);
	return (len);
}

int	ft_put_ptr(unsigned long long n, const char *base, size_t base_len)
{
	int	count;

	count = 0;
	count += ft_put_string("0x");
	if (n == 0)
		count += ft_put_char('0');
	else
		count += ft_put_ux_num(n, base, base_len);
	return (count);
}
