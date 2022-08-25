/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:56:10 by fyardimc          #+#    #+#             */
/*   Updated: 2022/07/25 21:12:36 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*arry;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	arry = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arry)
		return (NULL);
	ft_strlcpy((arry), (char *)s1, s1_len + s2_len + 1);
	ft_strlcpy((arry + s1_len), (char *)s2, s1_len + s2_len + 1);
	free(s1);
	return (arry);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen((char *)s)]);
	while ((*s != (char)c) && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen((char *)src);
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

char	*get_line(char *line)
{
	char	*end;
	char	*arr;

	if (!*line)
		return (NULL);
	end = ft_strchr(line, '\n');
	if (end == NULL)
	{
		end = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!end)
			return (NULL);
		ft_strlcpy(end, line, ft_strlen(line) + 1);
		return (end);
	}
	arr = malloc(sizeof(char) * (end - line + 2));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, line, end - line + 2);
	return (arr);
}

char	*skip_next_n(char *line)
{
	char	*end;
	char	*arr;

	end = ft_strchr(line, '\n');
	if (end)
	{
		end++;
		arr = malloc(sizeof(char) * ft_strlen(end) + 1);
		if (!arr)
			return (NULL);
		ft_strlcpy(arr, end, ft_strlen(end) + 1);
		free(line);
		return (arr);
	}
	free(line);
	return (NULL);
}
