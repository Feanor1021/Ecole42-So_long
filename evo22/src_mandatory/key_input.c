/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:22:09 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:57 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_action(t_game *so_long, int x, int y)
{
	if (so_long->map[x][y] != '1')
	{
		if (so_long->map[x][y] == 'C')
		{
			so_long->collect_num--;
		}
		if (so_long->map[x][y] == 'E' && so_long->collect_num < 1)
		{
			ft_printf("%sMoves: %d%s\n", GREEN, ++(so_long->move_num), END);
			free_2d_map(so_long);
			win_screen();
			exit(1);
		}
		if (so_long->map[x][y] == 'E')
		{
			return (0);
		}
		ft_printf("%sMoves: %d\n%s", GREEN, ++(so_long->move_num), END);
		return (1);
	}
	return (0);
}

void	right_left(int keycode, t_game *so_long)
{
	if (keycode == D_KEY || keycode == RIGHT_KEY)
	{
		if (check_action(so_long, so_long->chr.px, so_long->chr.py + 1))
		{
			so_long->map[so_long->chr.px][so_long->chr.py + 1] = '0';
			so_long->map[so_long->chr.px][so_long->chr.py] = '0';
			so_long->chr.py++;
			so_long->map[so_long->chr.px][so_long->chr.py] = 'P';
			so_long->chr.curr_pos = 'R';
		}
	}
	else if (keycode == A_KEY || keycode == LEFT_KEY)
	{
		if (check_action(so_long, so_long->chr.px, so_long->chr.py - 1))
		{
			so_long->map[so_long->chr.px][so_long->chr.py - 1] = '0';
			so_long->map[so_long->chr.px][so_long->chr.py] = '0';
			so_long->chr.py--;
			so_long->map[so_long->chr.px][so_long->chr.py] = 'P';
			so_long->chr.curr_pos = 'L';
		}
	}
}

void	up_down(int keycode, t_game *so_long)
{
	if (keycode == W_KEY || keycode == UP_KEY)
	{
		if (check_action(so_long, so_long->chr.px - 1, so_long->chr.py))
		{
			so_long->map[so_long->chr.px - 1][so_long->chr.py] = '0';
			so_long->map[so_long->chr.px][so_long->chr.py] = '0';
			so_long->chr.px--;
			so_long->map[so_long->chr.px][so_long->chr.py] = 'P';
			so_long->chr.curr_pos = 'U';
		}
	}
	else if (keycode == S_KEY || keycode == DOWN_KEY)
	{
		if (check_action(so_long, so_long->chr.px + 1, so_long->chr.py))
		{
			so_long->map[so_long->chr.px + 1][so_long->chr.py] = '0';
			so_long->map[so_long->chr.px][so_long->chr.py] = '0';
			so_long->chr.px++;
			so_long->map[so_long->chr.px][so_long->chr.py] = 'P';
			so_long->chr.curr_pos = 'D';
		}
	}
}

int	key_hook(int keycode, t_game *so_long)
{
	if (keycode == ESC_KEY)
	{
		exit_screen();
		free_2d_map(so_long);
		exit(1);
	}
	else if (keycode == D_KEY || keycode == A_KEY || keycode == LEFT_KEY
		|| keycode == RIGHT_KEY)
		right_left(keycode, so_long);
	else if (keycode == W_KEY || keycode == S_KEY || keycode == UP_KEY
		|| keycode == DOWN_KEY)
		up_down(keycode, so_long);
	mlx_clear_window(so_long->mlx, so_long->win);
	render_map(so_long);
	return (0);
}

void	key_input(t_game *so_long)
{
	mlx_hook(so_long->win, 2, 1L << 0, key_hook, so_long);
	mlx_hook(so_long->win, 17, 1L << 17, close_screen, so_long);
}
