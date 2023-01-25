/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:22:50 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:57 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		mlx_loop(so_long.mlx);
	}
	else
		ft_printf("%susage: <./so_long> <map_file>!!%s", YELLOW, END);
}
