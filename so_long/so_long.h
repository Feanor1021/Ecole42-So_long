#ifndef SO_LONG_H
# define SO_LONG_H

#include "./gnl/get_next_line.h"
#include "./ft_printf/include/ft_printf.h"
#include <stdio.h>

typedef struct node
{
    int *map_sizes;
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

//map control and create functions
void map_control(t_game *so_long, char* map_name);
void map_sizes(t_game *sol,char *argv);
void map_create(t_game *so_long,char *argv);
t_flood **map_cpy_ff(t_game *so_long,char c);
int ft_find_val(t_flood **mapcpy, int x ,int y);
int coordinate_finder(t_game *s_l,char c);
int path_finder(t_game*s,t_flood **mapcpy,int px, int py);
void flood_fill_map(t_game *s, t_flood **mapcpy, int x, int y);
int check_diff_char_check(t_game *so_long, char* set);
void check_missing_char(t_game *s_l, int * flag1, int *flag2);
int	search_in_set(char s, char const *c);
int wall_check(t_game *so_long);
int valid_path_check();

void ft_error();

//libft functions
int	ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen2(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);

#endif