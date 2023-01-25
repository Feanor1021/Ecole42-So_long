/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:25:55 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:47:02 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_score(t_game *so_long)
{
	char	*move;
	char	*str;

	move = ft_itoa(so_long->move_num);
	str = ft_strjoin(ft_strdup("Move:"), move);
	mlx_string_put(so_long->mlx, so_long->win, 26, 36, 0xABFFFFFF, str);
	free(str);
	free(move);
}

int	main(int argc, char **argv)
{
	t_game	so_long;

	so_long.collect_num = 0;
	so_long.move_num = 0;
	so_long.map = NULL;
	if (argc == 2)
	{
		map_control(&so_long, argv[1]);
		so_long.mlx = mlx_init();
		configure_settings(&so_long);
		key_input(&so_long);
		mlx_loop_hook(so_long.mlx, render_back, &so_long);
		mlx_loop(so_long.mlx);
	}
	else
		ft_printf("%susage: <./so_long> <map_file>!!%s", YELLOW, END);
}
