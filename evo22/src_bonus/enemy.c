/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:14:52 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:46:57 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_collectables(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->collect.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->collect.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= (5 * 4) && i < (5 * 8))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->collect.frame3, so_long->flag, so_long->flag2);
	}
	if (i == (5 * 8))
		i = 0;
	i++;
}

void	enemy(t_game *s, int *x, int *y, int *flag)
{
	if (*flag == 0)
	{
		if (s->map[*x + 1][*y] == '1'
		|| s->map[*x + 1][*y] == 'C' || s->map[*x + 1][*y] == 'E')
			*flag = 1;
		if (s->map[*x + 1][*y] != '1' && s->map[*x + 1][*y] != 'E' && s->map[*x
			+ 1][*y] != 'C')
			sub_function(s, 1, x, y);
	}
	else
	{
		if (s->map[*x - 1][*y] == '1' || s->map[*x - 1][*y] == 'C'
		|| s->map[*x - 1][*y] == 'E')
			*flag = 0;
		if (s->map[*x - 1][*y] != '1' && s->map[*x - 1][*y] != 'E' && s->map[*x
			- 1][*y] != 'C')
			sub_function(s, 0, x, y);
	}
}

void	sub_function(t_game *s, int flag, int *x, int *y)
{
	if (flag == 1)
	{
		s->map[*x][*y] = '0';
		(*x)++;
		s->map[*x][*y] = 'F';
	}
	else
	{
		s->map[*x][*y] = '0';
		(*x)--;
		s->map[*x][*y] = 'F';
	}
}
