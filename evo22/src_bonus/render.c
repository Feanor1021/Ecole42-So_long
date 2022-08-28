/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:28:38 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:33:50 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image1(t_game *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->back_ground.frame1, so_long->flag, so_long->flag2);
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == '1')
	{
		if ((so_long->flag2 / 64) == so_long->map_sizes[1] - 1)
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->walls.frame1, so_long->flag, so_long->flag2);
		else
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->walls.frame2, so_long->flag, so_long->flag2);
	}
	put_image2(so_long);
}

void	put_image2(t_game *so_long)
{
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'P')
	{
		if (so_long->chr.curr_pos == 'R')
			animation_player_r(so_long);
		else if (so_long->chr.curr_pos == 'L')
			animation_player_l(so_long);
		else if (so_long->chr.curr_pos == 'U')
			animation_player_u(so_long);
		else if (so_long->chr.curr_pos == 'D')
			animation_player_d(so_long);
	}
}

void	put_image3(t_game *so_long)
{
	put_image1(so_long);
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'C')
		animation_collectables(so_long);
	else if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'E')
	{
		if (so_long->collect_num != 0)
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->exit_door.frame1, so_long->flag, so_long->flag2);
		else
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->exit_door.frame2, so_long->flag, so_long->flag2);
	}
	else if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'F')
		animation_enemy(so_long);
	so_long->flag += 64;
}

void	render_map(t_game *s)
{
	s->i = 0;
	s->j = 0;
	s->flag = 0;
	s->flag2 = 0;
	while (s->i < s->map_sizes[1])
	{
		s->j = 0;
		while (s->j < s->map_sizes[0])
		{
			put_image3(s);
			put_score(s);
			if (s->map[s->chr.px][s->chr.py] == 'F')
			{
				lose_screen(s);
			}
			s->j++;
		}
		s->flag = 0;
		s->flag2 += 64;
		s->i++;
	}
}

int	render_back(t_game *so_long)
{
	static int	flag;
	static int	i;

	coordinate_finder(so_long, 'F');
	delay(40);
	if (i == 5)
	{
		enemy(so_long, &so_long->i, &so_long->j, &flag);
		i = 0;
	}
	else
		i++;
	render_map(so_long);
	return (1);
}
