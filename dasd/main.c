#include "so_long.h"

void so_long_start()
{
    ft_printf("%s███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗%s\n",BLUE,END);
    ft_printf("%s██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝%s\n",BLUE,END);
    ft_printf("%s███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗%s\n",BLUE,END);
    ft_printf("%s╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║%s\n",BLUE,END);
    ft_printf("%s███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝%s\n",BLUE,END);
    ft_printf("%s╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝\n%s",BLUE,END);
}

int main(int argc, char **argv)
{
    t_game so_long;

    if(argc == 2)
    {
        so_long_start();
        map_control(&so_long,argv[1]);
    }
    else
        ft_printf("%susage: <./so_long> <map_file>!!%s",YELLOW,END);
    print_map(so_long);
}
