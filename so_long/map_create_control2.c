#include "so_long.h"


int coordinate_finder(t_game *s_l,char c)
{
    if(c == 'P' || c=='E')
    {
        s_l->i = 0;
        s_l->j = 0;
    }
    if(c == 'C'&&s_l->i != 8)
    {
        s_l->j++;
    }
    while(s_l->i<=s_l->map_sizes[1]-1)
    {
        while (s_l->j<=s_l->map_sizes[0]-1)
        {
            if(s_l->map[s_l->i][s_l->j] == c)
                return 1;
            s_l->j++;
        }
        s_l->j=0;
        s_l->i++;
    }
    return 0;
}

t_flood **map_cpy_ff(t_game *so_long,char c)
{
    t_flood **mapcpy;
    int i;
    int j;

    i = -1;
    mapcpy=(t_flood**)malloc(sizeof(t_flood *)*so_long->map_sizes[1]);
    while(i++<so_long->map_sizes[1]-1)
        mapcpy[i]=(t_flood*)malloc(sizeof(t_flood)*so_long->map_sizes[0]+1);
    i = -1;
    while (i++ < so_long->map_sizes[1]-1)
    {
        j = -1;
        while (j++ < so_long->map_sizes[0]-1)
        {
            if(so_long->map[i][j]=='1')
                mapcpy[i][j].data='-';
            else
                mapcpy[i][j].data='*';
            if(so_long->map[i][j]=='E'&&c!='E')
                mapcpy[i][j].data='-';
            mapcpy[i][j].fil_fg=0;
            mapcpy[i][j].num=-1;
        }
    }
    return mapcpy;
}

int valid_path_check(t_game *so_long)
{
    int pxy[2];
    t_flood **mapcpy;;

    coordinate_finder(so_long,'P');
    pxy[0]=so_long->i;
    pxy[1]=so_long->j;
    so_long->i = 0;
    so_long->j = 0;
    while(coordinate_finder(so_long,'C'))
    {
        mapcpy=map_cpy_ff(so_long,'G');
        if(!path_finder(so_long,mapcpy,pxy[0],pxy[1]))
            return -1;        
    }
    coordinate_finder(so_long,'E');
    mapcpy=map_cpy_ff(so_long,'E');
    if(!path_finder(so_long,mapcpy,pxy[0],pxy[1]))
        return -1;
    return 1;
}

int ft_find_val(t_flood **mapcpy, int x ,int y)
{
    if(mapcpy[x][y-1].fil_fg==1&& mapcpy[x][y-1].data!='-')
        return mapcpy[x][y-1].num+1;
    if(mapcpy[x][y+1].fil_fg==1&& mapcpy[x][y+1].data!='-')
        return mapcpy[x][y+1].num+1;
    if(mapcpy[x-1][y].fil_fg==1&& mapcpy[x-1][y].data!='-')
        return mapcpy[x-1][y].num+1;
    else
        return mapcpy[x+1][y].num+1;   
}

void flood_fill_map(t_game *s, t_flood **mapcpy, int x, int y)
{
    if(mapcpy[x][y].fil_fg==0 && mapcpy[x][y].data!='-')
    {
        mapcpy[x][y].num=ft_find_val(mapcpy,x,y);
        mapcpy[x][y].fil_fg=1;
        flood_fill_map(s,mapcpy,x-1,y);
        flood_fill_map(s,mapcpy,x+1,y);
        flood_fill_map(s,mapcpy,x,y-1);
        flood_fill_map(s,mapcpy,x,y+1);
    }
}

int path_finder(t_game*s,t_flood **mapcpy,int px, int py)
{
    flood_fill_map(s,mapcpy,s->i,s->j);
    if(mapcpy[px][py].num==-1)
        return 0;
    while(mapcpy[px][py].num!=0)
    {
        if((mapcpy[px][py].num>mapcpy[px-1][py].num)&&mapcpy[px-1][py].fil_fg==1)
            px--;
        if((mapcpy[px][py].num>mapcpy[px+1][py].num)&&mapcpy[px+1][py].fil_fg==1)
            px++;
        if((mapcpy[px][py].num>mapcpy[px][py-1].num)&&mapcpy[px][py-1].fil_fg==1)
            py--;
        if((mapcpy[px][py].num>mapcpy[px][py+1].num)&&mapcpy[px][py+1].fil_fg==1)
            py++;
    }
    if((px==s->i && py ==s->j))
        return 1;
    return 0;
}