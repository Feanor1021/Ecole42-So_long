/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:36:29 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/28 16:46:22 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include ".././ft_printf/include/ft_printf.h"
# include ".././gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <limits.h>
# include <time.h>

typedef struct t_assets
{
	void		*frame1;
	void		*frame2;
	void		*frame3;
	void		*frame4;
	int			width;
	int			height;
}				t_assets;

typedef struct t_char
{
	t_assets	c_u;
	t_assets	c_d;
	t_assets	c_l;
	t_assets	c_r;
	char		curr_pos;
	int			px;
	int			py;
}				t_char;

typedef struct node
{
	int			map_sizes[2];
	char		**map;
	void		*mlx;
	void		*win;
	t_char		chr;
	t_assets	walls;
	t_assets	back_ground;
	t_assets	collect;
	t_assets	exit_door;
	t_assets	enemy;
	int			collect_num;
	int			move_num;
	int			flag;
	int			flag2;
	int			flag3;
	int			i;
	int			j;
}				t_game;

typedef struct flood_fill
{
	char		num;
	char		data;
	int			fil_fg;
}				t_flood;

//keys
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124

//color
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"
# define BLUE "\e[0;34m"

//map control and create functions
void			map_control(t_game *so_long, char *map_name);
int				map_sizes(t_game *sol, char *argv);
int				map_create(t_game *so_long, char *argv);
int				search_in_set(char s, char const *c);
int				wall_check(t_game *so_long);
int				check_diff_char_check(t_game *so_long, char *set);
void			check_missing_char(t_game *s_l, int *flag1, int *flag2);
int				is_map_file_valid(char *map_name);

//mlx
void			render_map(t_game *s);
void			put_image1(t_game *so_long);
void			put_image2(t_game *so_long);
void			put_image3(t_game *so_long);
void			configure_settings(t_game *so_long);
void			xpm_to_img(t_game *so_long);
void			xpm_to_img2(t_game *so_long);
void			xpm_to_img3(t_game *so_long);
void			put_score(t_game *so_long);
int				render_back(t_game *so_long);
void			animation_collectables(t_game *so_long);
void			animation_player_r(t_game *so_long);
void			animation_player_l(t_game *so_long);
void			animation_player_u(t_game *so_long);
void			animation_player_d(t_game *so_long);
void			enemy(t_game *so_long, int *x, int *y, int *flag);
void			animation_enemy(t_game *so_long);
void			sub_function(t_game *s, int flag, int *x, int *y);

void			delay(int milliseconds);
//key
void			key_input(t_game *so_long);
int				key_hook(int keycode, t_game *so_long);
void			up_down(int keycode, t_game *so_long);
void			right_left(int keycode, t_game *so_long);
int				check_action(t_game *so_long, int x, int y);

//path control functions
int				valid_path_check(t_game *so_long, t_flood ***mapcpy);
int				coordinate_finder(t_game *s_l, char c);
t_flood			**map_cpy(t_game *so_long, t_flood ***mapcpy, char c);
int				path_controller(t_game *s, t_flood ***mapcpy, int px, int py);
void			path_finder(t_game *s, t_flood ***mapcpy, int x, int y);
int				find_next_val(t_flood **mapcpy, int x, int y);

//errors and free functions
void			ft_error(t_game *so_long, t_flood ***mapcpy, int flag);
void			free_2d_cpy(t_flood ***argv, t_game *so_long);
void			free_2d_map(t_game *so_long);

//libft functions
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen2(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strrchr(const char *s, int c);
void			print_map(t_game so_long);
void			print_map2(t_game so_long, t_flood **mapcpy);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
//screens
void			so_long_start(void);
void			win_screen(t_game *so_long);
void			lose_screen(t_game *so_long);
void			exit_screen(void);
int				close_screen(t_game *so_long);

#endif