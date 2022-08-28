/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:21:50 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:57 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d_cpy(t_flood ***argv, t_game *so_long)
{
	int	i;

	if (!*argv || !argv)
		return ;
	if (so_long->map_sizes[0] == 0 || so_long->map_sizes[1] == 0)
		return ;
	i = so_long->map_sizes[1] - 1;
	while (i >= 0)
	{
		free((*argv)[i]);
		i--;
	}
	if (*argv)
		free(*argv);
}

void	free_2d_map(t_game *so_long)
{
	int	i;

	if (!so_long->map || so_long->map_sizes[0] == 0
		|| so_long->map_sizes[1] == 0)
		return ;
	i = 0;
	i = so_long->map_sizes[1] - 1;
	while (i >= 0)
	{
		free((so_long->map)[i]);
		i--;
	}
	free(so_long->map);
}

void	ft_error(t_game *so_long, t_flood ***mapcpy, int flag)
{
	free_2d_cpy(mapcpy, so_long);
	free_2d_map(so_long);
	if (flag == 1)
		ft_printf("%sError\nWrong file extension!!%s\n", RED, END);
	else if (flag == 2)
		ft_printf("%sError\nMap cannot created!!%s\n", RED, END);
	else if (flag == 3)
		ft_printf("%sError\nWrong wall format!!%s\n", RED, END);
	else if (flag == 4)
		ft_printf("%sError\nInvalid entity quantity!!%s\n", RED, END);
	else
		ft_printf("%sError\nThere is a invalid path!!%s\n", RED, END);
	exit(1);
}
