/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:33:56 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:33:34 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	find_digit_num(int num)
{
	int	dnum;

	dnum = 0;
	if (num == -2147483648)
		return (11);
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num = num * -1;
		dnum++;
	}
	while (num > 0)
	{
		num /= 10;
		dnum++;
	}
	return (dnum);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*arry;

	digit = find_digit_num(n);
	arry = (char *)malloc(sizeof(char) * (digit + 1));
	if (!arry)
		return (NULL);
	arry[digit] = '\0';
	digit--;
	if (n == -2147483648)
		ft_strlcpy(arry, "-2147483648", 12);
	else if (n == 0)
		ft_strlcpy(arry, "0", 2);
	if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		arry[0] = '-';
	}
	while (digit >= 0 && n > 0 && n != -2147483648)
	{
		arry[digit] = n % 10 + '0';
		digit--;
		n /= 10;
	}
	return (arry);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*opr;

	s1_len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	opr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (opr)
	{
		i = 0;
		while (s1[i])
		{
			opr[i] = s1[i];
			i++;
		}
		opr[i] = '\0';
	}
	return (opr);
}

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < (unsigned long)pause)
	{
		now = clock();
	}
	return ;
}
