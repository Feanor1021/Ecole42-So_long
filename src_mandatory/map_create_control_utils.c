/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_control_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:23:12 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 14:24:54 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_in_set(char s, char const *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

void	check_missing_char(t_game *s_l, int *flag1, int *flag2)
{
	if (s_l->map[s_l->i][s_l->j] == 'E')
		s_l->flag++;
	if (s_l->map[s_l->i][s_l->j] == 'P')
		s_l->flag2++;
	if (s_l->map[s_l->i][s_l->j] == 'C')
		*flag1 = 1;
	if (s_l->map[s_l->i][s_l->j] == '0')
		*flag2 = 1;
}

int	is_map_file_valid(char *map_name)
{
	char	*ret;

	ret = ft_strrchr(map_name, '.');
	if (!ret)
		return (-1);
	if (ret[0] == '.' && ret[1] == 'b' && ret[2] == 'e' && ret[3] == 'r'
		&& ret[4] == '\0')
		return (1);
	return (-1);
}

int	find_next_val(t_flood **mapcpy, int x, int y)
{
	if ((mapcpy)[x][y - 1].fil_fg == 1 && (mapcpy)[x][y - 1].data != '-')
		return ((mapcpy)[x][y - 1].num + 1);
	if ((mapcpy)[x][y + 1].fil_fg == 1 && (mapcpy)[x][y + 1].data != '-')
		return ((mapcpy)[x][y + 1].num + 1);
	if ((mapcpy)[x - 1][y].fil_fg == 1 && (mapcpy)[x - 1][y].data != '-')
		return ((mapcpy)[x - 1][y].num + 1);
	else
		return ((mapcpy)[x + 1][y].num + 1);
}
