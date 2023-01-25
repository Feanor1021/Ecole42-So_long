/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:25:37 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:25:37 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image1(t_game *so_long)
{
	put_image2(so_long);
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->collect.frame2, so_long->flag, so_long->flag2);
	else if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'E')
	{
		if (so_long->collect_num != 0)
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->exit_door.frame1, so_long->flag, so_long->flag2);
		else
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->exit_door.frame2, so_long->flag, so_long->flag2);
	}
	so_long->flag += 64;
}

void	put_image2(t_game *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		so_long->back_ground.frame1, so_long->flag, so_long->flag2);
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->walls.frame1, so_long->flag, so_long->flag2);
	if (so_long->map[so_long->flag2 / 64][so_long->flag / 64] == 'P')
	{
		if (so_long->chr.curr_pos == 'R')
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->chr.c_r.frame1, so_long->flag, so_long->flag2);
		else if (so_long->chr.curr_pos == 'L')
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->chr.c_l.frame1, so_long->flag, so_long->flag2);
		else if (so_long->chr.curr_pos == 'U')
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->chr.c_u.frame1, so_long->flag, so_long->flag2);
		else if (so_long->chr.curr_pos == 'D')
			mlx_put_image_to_window(so_long->mlx, so_long->win,
				so_long->chr.c_d.frame1, so_long->flag, so_long->flag2);
	}
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
			put_image1(s);
			s->j++;
		}
		s->flag = 0;
		s->flag2 += 64;
		s->i++;
	}
}
