/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:11:09 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:32:50 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation_enemy(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->enemy.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->enemy.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= (5 * 4) && i < (5 * 8))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->enemy.frame3, so_long->flag, so_long->flag2);
	}
	if (i == (5 * 8))
		i = 0;
	i++;
}

void	animation_player_u(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_u.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_u.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i == (5 * 4))
		i = 0;
	i++;
}

void	animation_player_d(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_d.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_d.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= (5 * 4) && i < (5 * 8))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_d.frame3, so_long->flag, so_long->flag2);
	}
	if (i == (5 * 8))
		i = 0;
	i++;
}

void	animation_player_r(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_r.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_r.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= (5 * 4) && i < (5 * 8))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_r.frame3, so_long->flag, so_long->flag2);
	}
	if (i == (5 * 8))
		i = 0;
	i++;
}

void	animation_player_l(t_game *so_long)
{
	static int	i;

	if (i > 0 && i < 5)
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_l.frame1, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= 5 && i < (5 * 4))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_l.frame2, so_long->flag, so_long->flag2);
		i += 2;
	}
	if (i >= (5 * 4) && i < (5 * 8))
	{
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->chr.c_l.frame3, so_long->flag, so_long->flag2);
	}
	if (i == (5 * 8))
		i = 0;
	i++;
}
