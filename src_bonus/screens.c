/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:31:12 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:47:52 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long_start(void)
{
	ft_printf("%s███████╗ ██████╗         ██╗      \
██████╗ ███╗   ██╗ ██████╗%s\n",
		BLUE, END);
	ft_printf("%s██╔════╝██╔═══██╗        \
██║     ██╔═══██╗████╗  ██║██╔════╝%s\n",
		BLUE, END);
	ft_printf("%s███████╗██║   ██║        \
██║     ██║   ██║██╔██╗ ██║██║  ███╗%s\n",
		BLUE, END);
	ft_printf("%s╚════██║██║   ██║        \
██║     ██║   ██║██║╚██╗██║██║   ██║%s\n",
		BLUE, END);
	ft_printf("%s███████║╚██████╔╝███████╗\
███████╗╚██████╔╝██║ ╚████║╚██████╔╝%s\n",
		BLUE, END);
	ft_printf("%s╚══════╝ ╚═════╝ ╚══════╝\
╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝\n%s",
		BLUE, END);
}

void	win_screen(t_game *so_long)
{
	free_2d_map(so_long);
	ft_printf("%s██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗██╗\n%s",
		GREEN, END);
	ft_printf("%s╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║██║\n%s",
		GREEN, END);
	ft_printf("%s ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║██║\n%s",
		GREEN, END);
	ft_printf("%s  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║╚═╝\n%s",
		GREEN, END);
	ft_printf("%s   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║██╗\n%s",
		GREEN, END);
	ft_printf("%s   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝\n%s",
		GREEN, END);
	exit(1);
}

void	lose_screen(t_game *so_long)
{
	free_2d_map(so_long);
	mlx_destroy_window(so_long->mlx, so_long->win);
	ft_printf("%s   ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      \
▄████████       ▄██████▄   ▄█    █▄     ▄████████    ▄████████\n%s",
		RED, END);
	ft_printf("%s  ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    \
███      ███    ███ ███    ███   ███    ███   ███    ███\n%s",
		RED, END);
	ft_printf("%s  ███    █▀    ███    ███ ███   ███   ███   ███    \
█▀       ███    ███ ███    ███   ███    █▀    ███    ███\n%s",
		RED, END);
	ft_printf("%s ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄\
          ███    ███ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀\n%s",
		RED, END);
	ft_printf("%s▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀\
          ███    ███ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀\n%s",
		RED, END);
	ft_printf("%s  ███    ███   ███    ███ ███   ███   ███   ███\
    █▄       ███    ███ ███    ███   ███    █▄  ▀███████████\n%s",
		RED, END);
	ft_printf("%s  ███    ███   ███    ███ ███   ███   ███   ███\
    ███      ███    ███ ███    ███   ███    ███   ███    ███\n%s",
		RED, END);
	ft_printf("%s  ████████▀    ███    █▀   ▀█   ███   █▀\
    ██████████       ▀██████▀   ▀██████▀    ██████████   ███    ███\n%s",
		RED, END);
	exit(1);
}

void	exit_screen(void)
{
	ft_printf("%s███████╗██╗  ██╗██╗████████╗\n%s", RED, END);
	ft_printf("%s██╔════╝╚██╗██╔╝██║╚══██╔══╝\n%s", RED, END);
	ft_printf("%s█████╗   ╚███╔╝ ██║   ██║\n%s", RED, END);
	ft_printf("%s██╔══╝   ██╔██╗ ██║   ██║\n%s", RED, END);
	ft_printf("%s███████╗██╔╝ ██╗██║   ██║\n%s", RED, END);
	ft_printf("%s╚══════╝╚═╝  ╚═╝╚═╝   ╚═╝\n%s", RED, END);
}

int	close_screen(t_game *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	free_2d_map(so_long);
	exit_screen();
	exit(1);
}
