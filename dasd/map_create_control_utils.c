#include "so_long.h"

int	search_in_set(char s, char const *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

void check_missing_char(t_game *s_l, int * flag1, int *flag2)
{
    if(s_l->map[s_l->i][s_l->j]=='E')
        s_l->flag++;
    if(s_l->map[s_l->i][s_l->j]=='P')
        s_l->flag2++;
    if(s_l->map[s_l->i][s_l->j]=='C')
        *flag1 = 1;
    if(s_l->map[s_l->i][s_l->j]=='0')
        *flag2 = 1;
}
