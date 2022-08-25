#include "so_long.h"

void map_control(t_game *so_long, char* map_name)
{
    if (ft_memcmp(ft_strrchr(map_name, '.'), ".ber", 4) != 0)
	    return (ft_error());
    map_create(so_long,map_name);
    if (wall_check(so_long)==-1) //wallcheck
        ft_error();
    if (check_diff_char_check(so_long,"01CEP")== -1) //diff karakter en az 1 e p c dublicate e p control missing char
        ft_error();
     /*   coordinate_finder(so_long,'P');
        printf("%d %d",so_long->i,so_long->j);
        int px;
        int py;
        px=so_long->i;
        py=so_long->j;
        so_long->i = 0;
        so_long->j = 0;
        coordinate_finder(so_long,'C');
        printf("%d %d",so_long->i,so_long->j);
        t_flood **map;
        map=map_cpy_ff(so_long,px,py);
        int i= 0;
        int j =0 ;

        for(i = 0;i<so_long->map_sizes[1];i++)
        {
        for(j = 0 ; j < so_long->map_sizes[0]; j++)
        {
            ft_printf("%c",map[i][j].data);
        }
        ft_printf("\n");
    }*/
    if (valid_path_check(so_long)==-1)
        ft_error();
}

int wall_check(t_game *so_long)
{
    int i;
    int j;

    j = -1;
    while (j++<so_long->map_sizes[0]-1)
        if(so_long->map[0][j]!='1' || 
        so_long->map[so_long->map_sizes[1]-1][j]!='1')
            return -1;
    i = -1;
    while (i++<so_long->map_sizes[1]-1)
         if(so_long->map[i][0]!='1' || 
         so_long->map[i][so_long->map_sizes[0]-1]!='1')
            return -1;
    return 1;
}

int check_diff_char_check(t_game *s_l, char* set)
{
    int flag; 
    int flag2;

    s_l->i = s_l->map_sizes[1]-1;
    s_l->flag = 0;
    s_l->flag2 = 0;
    while (s_l->i>=0)
    {
        s_l->j = s_l->map_sizes[0]-1;
        while(s_l->j>=0)
        {
            if(!search_in_set(s_l->map[s_l->i][s_l->j],set))
                return -1;
            check_missing_char(s_l,&flag,&flag2);
            s_l->j--;
        }
        s_l->i--;
    }
    if(s_l->flag !=1 || s_l->flag2 !=1 
        || flag == 0 || flag2==0)
        return -1;
    return 1;
}

void map_sizes(t_game *sol,char *argv)
{
    char *row;
    int fd;

    sol->map_sizes=(int *)malloc(sizeof(int)*2);
    fd=open(argv,O_RDONLY);
    if(fd == -1)
        ft_error();
    row=get_next_line(fd);
    (sol)->map_sizes[0]=ft_strlen2(row);
    (sol)->map_sizes[1]=1;
    while(1)
    {
        free(row);
        row=get_next_line(fd);
        sol->flag=ft_strlen2(row);
        (sol)->map_sizes[1]++;
        if(!ft_strchr(row,'\n') && sol->flag == sol->map_sizes[0])
            break;
        if(sol->flag!=(sol)->map_sizes[0])
            ft_error();
    }
    free(row);
    close(fd);
}

void map_create(t_game *so_long, char* argv)
{
    int fd;
    char *row;
    int i;

    map_sizes(so_long,argv);
    i = 0;
    fd = open(argv,O_RDONLY);
    if(fd == -1)
        ft_error();
    so_long->map=(char **)malloc(sizeof(char *)*(so_long->map_sizes[1]));
    row=get_next_line(fd);
    while (i<=so_long->map_sizes[0])
    {
        so_long->map[i]=(char *)malloc(sizeof(char)*(so_long->map_sizes[0]+1));
        ft_strlcpy(so_long->map[i],row,so_long->map_sizes[0]+1);
        free(row);
        row=get_next_line(fd);
        if(!row)
            break;
        i++;
    }
    close(fd);
}