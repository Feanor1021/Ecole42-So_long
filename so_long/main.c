#include "so_long.h"


int main(int argc, char **argv)
{
    t_game so_long;
    int i,j;
    i = 0;
    j = 0;

    if(argc == 2)
        map_control(&so_long,argv[1]);
    else
        ft_printf("usage: <./so_long> <map_file>");

    
    for(i = 0;i<so_long.map_sizes[1];i++)
    {
        for(j = 0 ; j < so_long.map_sizes[0]; j++)
        {
            ft_printf("%c",so_long.map[i][j]);
        }
        ft_printf("\n");
    }

}
