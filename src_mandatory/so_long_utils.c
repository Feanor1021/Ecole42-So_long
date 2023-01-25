/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:28:28 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:56:48 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (so_long.map == NULL)
		return ;
	while (i < so_long.map_sizes[1])
	{
		j = 0;
		while (j < so_long.map_sizes[0])
		{
			ft_printf("%c", so_long.map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map2(t_game so_long, t_flood **mapcpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < so_long.map_sizes[1])
	{
		j = 0;
		while (j < so_long.map_sizes[0])
		{
			ft_printf("%d ", mapcpy[i][j].num);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i) && *(s + i) != '\n')
		i++;
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		dif;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n))
	{
		dif = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	size_s;

	size_s = ft_strlen(s);
	while (size_s >= 0)
	{
		if (((char *)s)[size_s] == (char)c)
			return ((char *)(s + size_s));
		size_s--;
	}
	return (NULL);
}
