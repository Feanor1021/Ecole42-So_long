#ifndef SO_LONG_H
# define SO_LONG_H

#include "./gnl/get_next_line.h"
#include "./ft_printf/include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include "mlx/mlx.h"

typedef struct node
{
    int map_sizes[2];
    char **map;
    void *mlx;

    int flag;
    int flag2;
    int i;
    int j;
    int px;
    int py;
} t_game;

typedef struct flood_fill
{
    char num;
    char data;
    int fil_fg;
}t_flood;

//color
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"
# define BLUE   "\e[0;34m"

//map control and create functions
void map_control(t_game *so_long, char* map_name);
int map_sizes(t_game *sol,char *argv);
int map_create(t_game *so_long,char *argv);
int	search_in_set(char s, char const *c);
int wall_check(t_game *so_long);
int check_diff_char_check(t_game *so_long, char* set);
void check_missing_char(t_game *s_l, int * flag1, int *flag2);

//path control functions
int valid_path_check(t_game *so_long,t_flood ***mapcpy);
int coordinate_finder(t_game *s_l,char c);
t_flood **map_cpy(t_game *so_long,t_flood ***mapcpy, char c);
int path_controller(t_game*s,t_flood ***mapcpy,int px, int py);
void path_finder(t_game *s, t_flood ***mapcpy, int x, int y);
int find_next_val(t_flood **mapcpy, int x ,int y);

//errors
void ft_error(t_game *so_long, t_flood ***mapcpy, int flag);
void	free_2d_cpy(t_flood ***argv,t_game *so_long);
void	free_2d_map(t_game *so_long);
//libft functions
int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen2(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
void print_map(t_game so_long);
void print_map2(t_game so_long, t_flood **mapcpy);

#endif