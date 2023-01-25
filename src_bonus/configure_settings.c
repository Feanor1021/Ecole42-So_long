/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:04:39 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:32:55 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xpm_to_img(t_game *s)
{
	s->walls.frame1 = mlx_xpm_file_to_image(s->mlx, "./xpm/walls/wall.xpm",
			&s->walls.width, &s->walls.height);
	s->walls.frame2 = mlx_xpm_file_to_image(s->mlx, "./xpm/walls/wall2.xpm",
			&s->walls.width, &s->walls.height);
	s->back_ground.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/back_ground.xpm",
			&s->back_ground.width, &s->back_ground.height);
	s->chr.c_l.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_left/char_left.xpm",
			&s->chr.c_l.width, &s->chr.c_l.height);
	s->chr.c_l.frame2 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_left/char_left3.xpm",
			&s->chr.c_l.width, &s->chr.c_l.height);
	s->chr.c_l.frame3 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_left/char_left2.xpm",
			&s->chr.c_l.width, &s->chr.c_l.height);
}

void	xpm_to_img2(t_game *s)
{
	s->chr.c_r.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_right/char_right.xpm",
			&s->chr.c_r.width, &s->chr.c_r.height);
	s->chr.c_r.frame2 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_right/char_right3.xpm",
			&s->chr.c_r.width, &s->chr.c_r.height);
	s->chr.c_r.frame3 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_right/char_right2.xpm", &s->chr.c_r.width,
			&s->chr.c_r.height);
	s->chr.c_u.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_up/char_back.xpm", &s->chr.c_u.width,
			&s->chr.c_u.height);
	s->chr.c_u.frame2 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_up/char_up2.xpm", &s->chr.c_u.width,
			&s->chr.c_u.height);
	s->chr.c_d.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_down/char_front.xpm", &s->chr.c_d.width,
			&s->chr.c_d.height);
	s->chr.c_d.frame2 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_down/char_down2.xpm", &s->chr.c_d.width,
			&s->chr.c_d.height);
	s->chr.c_d.frame3 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/char_down/char_down3.xpm", &s->chr.c_d.width,
			&s->chr.c_d.height);
}

void	xpm_to_img3(t_game *s)
{
	s->exit_door.frame1 = mlx_xpm_file_to_image(s->mlx, "./xpm/exit.xpm",
			&s->walls.width, &s->walls.height);
	s->exit_door.frame2 = mlx_xpm_file_to_image(s->mlx, "./xpm/exit2.xpm",
			&s->walls.width, &s->walls.height);
	s->collect.frame1 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/collectables/collect.xpm", &s->collect.width,
			&s->collect.height);
	s->collect.frame2 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/collectables/collect2.xpm", &s->collect.width,
			&s->collect.height);
	s->collect.frame3 = mlx_xpm_file_to_image(s->mlx,
			"./xpm/collectables/collect3.xpm", &s->collect.width,
			&s->collect.height);
	(s->enemy).frame1 = mlx_xpm_file_to_image(s->mlx, "./xpm/enemy/enemy.xpm",
			&s->enemy.width, &s->enemy.height);
	(s->enemy).frame2 = mlx_xpm_file_to_image(s->mlx, "./xpm/enemy/enemy2.xpm",
			&s->enemy.width, &s->enemy.height);
	(s->enemy).frame3 = mlx_xpm_file_to_image(s->mlx, "./xpm/enemy/enemy3.xpm",
			&s->enemy.width, &s->enemy.height);
}

void	configure_settings(t_game *s)
{
	xpm_to_img(s);
	xpm_to_img2(s);
	xpm_to_img3(s);
	s->win = mlx_new_window(s->mlx, (s->map_sizes[0]) * 64, (s->map_sizes[1])
			* 64, "*Frogi*");
	s->chr.curr_pos = 'L';
	render_map(s);
}
