#include "so_long.h"



void ft_error()
{
    ft_printf("Error\n");
    exit(1);
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;
    if(!s)
      return   0;
	i = 0;
	while (*(s + i)&&*(s+i)!='\n')
		i++;
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		dif;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n))
	{
		dif = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	size_s;

	size_s = ft_strlen(s);
	while (size_s >= 0)
	{
		if (((char *)s)[size_s] == (char)c)
			return ((char *)(s + size_s));
		size_s--;
	}
	return (NULL);
}

