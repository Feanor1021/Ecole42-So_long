/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:24:39 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:56:38 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coordinate_finder(t_game *s_l, char c)
{
	if (c == 'P' || c == 'E')
	{
		s_l->i = 0;
		s_l->j = 0;
	}
	if (c == 'C' && s_l->i != s_l->map_sizes[1])
	{
		s_l->j++;
	}
	while (s_l->i <= s_l->map_sizes[1] - 1)
	{
		while (s_l->j <= s_l->map_sizes[0] - 1)
		{
			if (s_l->map[s_l->i][s_l->j] == c)
				return (1);
			s_l->j++;
		}
		s_l->j = 0;
		s_l->i++;
	}
	return (0);
}

t_flood	**map_cpy(t_game *so_long, t_flood ***mapcpy, char c)
{
	int	i;
	int	j;

	i = -1;
	(*mapcpy) = (t_flood **)malloc(sizeof(t_flood *) * so_long->map_sizes[1]);
	while (i++ < so_long->map_sizes[1] - 1)
		(*mapcpy)[i] = (t_flood *)malloc(sizeof(t_flood) * so_long->map_sizes[0]
				+ 1);
	i = -1;
	while (i++ < so_long->map_sizes[1] - 1)
	{
		j = -1;
		while (j++ < so_long->map_sizes[0] - 1)
		{
			if (so_long->map[i][j] == '1')
				(*mapcpy)[i][j].data = '-';
			else
				(*mapcpy)[i][j].data = '*';
			if (so_long->map[i][j] == 'E' && c != 'E')
				(*mapcpy)[i][j].data = '-';
			(*mapcpy)[i][j].fil_fg = 0;
			(*mapcpy)[i][j].num = -1;
		}
	}
	return (*mapcpy);
}

int	valid_path_check(t_game *so_long, t_flood ***mapcpy)
{
	coordinate_finder(so_long, 'P');
	so_long->chr.px = so_long->i;
	so_long->chr.py = so_long->j;
	so_long->i = 0;
	so_long->j = 0;
	so_long->collect_num = 0;
	while (coordinate_finder(so_long, 'C'))
	{
		so_long->collect_num++;
		*mapcpy = map_cpy(so_long, mapcpy, 'G');
		if (!path_controller(so_long, mapcpy, so_long->chr.px, so_long->chr.py))
			return (-1);
		free_2d_cpy(mapcpy, so_long);
	}
	coordinate_finder(so_long, 'E');
	*mapcpy = map_cpy(so_long, mapcpy, 'E');
	if (!path_controller(so_long, mapcpy, so_long->chr.px, so_long->chr.py))
		return (-1);
	free_2d_cpy(mapcpy, so_long);
	return (1);
}

void	path_finder(t_game *s, t_flood ***mapcpy, int x, int y)
{
	if ((*mapcpy)[x][y].fil_fg == 0 && (*mapcpy)[x][y].data != '-')
	{
		(*mapcpy)[x][y].num = find_next_val((*mapcpy), x, y);
		(*mapcpy)[x][y].fil_fg = 1;
		path_finder(s, mapcpy, x - 1, y);
		path_finder(s, mapcpy, x + 1, y);
		path_finder(s, mapcpy, x, y - 1);
		path_finder(s, mapcpy, x, y + 1);
	}
}

int	path_controller(t_game *s, t_flood ***mapcpy, int px, int py)
{
	px = s->chr.px;
	py = s->chr.py;
	path_finder(s, mapcpy, s->i, s->j);
	if ((*mapcpy)[px][py].num == -1)
		return (0);
	while ((*mapcpy)[px][py].num != 0)
	{
		if (((*mapcpy)[px][py].num > (*mapcpy)[px - 1][py].num) && (*mapcpy)[px
			- 1][py].fil_fg == 1 && (*mapcpy)[px - 1][py].data == '*')
			px--;
		else if (((*mapcpy)[px][py].num > (*mapcpy)[px + 1][py].num)
				&& (*mapcpy)[px + 1][py].fil_fg == 1 && (*mapcpy)[px
				+ 1][py].data == '*')
			px++;
		else if (((*mapcpy)[px][py].num > (*mapcpy)[px][py - 1].num)
				&& (*mapcpy)[px][py - 1].fil_fg == 1 && (*mapcpy)[px][py
				- 1].data == '*')
			py--;
		else
			py++;
	}
	if ((px == s->i && py == s->j))
		return (1);
	return (0);
}
