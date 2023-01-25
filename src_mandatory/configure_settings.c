/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:18:17 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:21:26 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_game *so_long)
{
	so_long->walls.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/walls/wall2.xpm", &so_long->walls.width,
			&so_long->walls.height);
	so_long->back_ground.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/back_ground.xpm", &so_long->back_ground.width,
			&so_long->back_ground.height);
	so_long->chr.c_u.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/char_up/char_back.xpm", &so_long->chr.c_u.width,
			&so_long->chr.c_u.height);
	so_long->chr.c_d.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/char_down/char_front.xpm", &so_long->chr.c_d.width,
			&so_long->chr.c_d.height);
}

void	xpm_to_img2(t_game *so_long)
{
	so_long->chr.c_l.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/char_left/char_left.xpm", &so_long->chr.c_l.width,
			&so_long->chr.c_l.height);
	so_long->chr.c_r.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/char_right/char_right.xpm", &so_long->chr.c_r.width,
			&so_long->chr.c_r.height);
	so_long->exit_door.frame1 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/exit.xpm", &so_long->walls.width, &so_long->walls.height);
	so_long->exit_door.frame2 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/exit2.xpm", &so_long->walls.width, &so_long->walls.height);
	so_long->collect.frame2 = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/collectables/collect2.xpm", &so_long->collect.width,
			&so_long->collect.height);
}

void	configure_settings(t_game *so_long)
{
	xpm_to_img(so_long);
	xpm_to_img2(so_long);
	so_long->win = mlx_new_window(so_long->mlx, (so_long->map_sizes[0]) * 64,
			(so_long->map_sizes[1]) * 64, "*Frogi*");
	so_long->chr.curr_pos = 'L';
	render_map(so_long);
}
