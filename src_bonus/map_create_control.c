/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:27:13 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:47:24 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_control(t_game *so_long, char *map_name)
{
	t_flood	**mapcpy;

	mapcpy = NULL;
	if (is_map_file_valid(map_name) == -1)
		ft_error(so_long, &mapcpy, 1);
	if (map_create(so_long, map_name) == -1)
		ft_error(so_long, &mapcpy, 2);
	if (wall_check(so_long) == -1)
		ft_error(so_long, &mapcpy, 3);
	if (check_diff_char_check(so_long, "01CEPF") == -1)
		ft_error(so_long, &mapcpy, 4);
	if (valid_path_check(so_long, &mapcpy) == -1)
		ft_error(so_long, &mapcpy, 5);
	so_long_start();
}

int	wall_check(t_game *so_long)
{
	int	i;
	int	j;

	j = -1;
	while (j++ < so_long->map_sizes[0] - 1)
		if (so_long->map[0][j] != '1' ||
			so_long->map[so_long->map_sizes[1] - 1][j] != '1')
			return (-1);
	i = -1;
	while (i++ < so_long->map_sizes[1] - 1)
		if (so_long->map[i][0] != '1' ||
			so_long->map[i][so_long->map_sizes[0] - 1] != '1')
			return (-1);
	return (1);
}

int	check_diff_char_check(t_game *s_l, char *set)
{
	int	flag;
	int	flag2;

	s_l->i = s_l->map_sizes[1] - 1;
	s_l->flag = 0;
	s_l->flag2 = 0;
	s_l->flag3 = 0;
	flag = 0;
	flag2 = 0;
	while (s_l->i >= 0)
	{
		s_l->j = s_l->map_sizes[0] - 1;
		while (s_l->j >= 0)
		{
			if (!search_in_set(s_l->map[s_l->i][s_l->j], set))
				return (-1);
			check_missing_char(s_l, &flag, &flag2);
			s_l->j--;
		}
		s_l->i--;
	}
	if (s_l->flag != 1 || s_l->flag2 != 1
		|| s_l->flag3 == 0 || flag == 0 || flag2 == 0)
		return (-1);
	return (1);
}

int	map_sizes(t_game *sol, char *argv)
{
	char	*row;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	row = get_next_line(fd);
	(sol)->map_sizes[0] = ft_strlen2(row);
	(sol)->map_sizes[1] = 1;
	while (1)
	{
		free(row);
		row = get_next_line(fd);
		sol->flag = ft_strlen2(row);
		(sol)->map_sizes[1]++;
		if (!ft_strchr(row, '\n') && sol->flag == sol->map_sizes[0])
			break ;
		if (sol->flag != (sol)->map_sizes[0])
			free(row);
		if (sol->flag != (sol)->map_sizes[0])
			return (-1);
	}
	free(row);
	close(fd);
	return (1);
}

int	map_create(t_game *so_long, char *argv)
{
	int		fd;
	char	*row;
	int		i;

	if (map_sizes(so_long, argv) == -1)
		return (-1);
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	so_long->map = (char **)malloc(sizeof(char *) * (so_long->map_sizes[1]));
	row = get_next_line(fd);
	while (i <= so_long->map_sizes[0])
	{
		so_long->map[i] = (char *)malloc(sizeof(char) * (so_long->map_sizes[0]
					+ 1));
		ft_strlcpy(so_long->map[i], row, so_long->map_sizes[0] + 1);
		free(row);
		row = get_next_line(fd);
		if (!row)
			break ;
		i++;
	}
	close(fd);
	return (1);
}
