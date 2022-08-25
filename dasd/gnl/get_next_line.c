/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:56:13 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/21 10:50:42 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_till_n(int fd, char *line)
{
	char	*buf;
	int		read_return;

	if (ft_strchr(line, '\n'))
		return (line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_return = 1;
	while (!ft_strchr(line, '\n') && read_return != 0)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_return] = '\0';
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_till_n(fd, line);
	if (!line)
		return (NULL);
	ret_line = get_line(line);
	line = skip_next_n(line);
	return (ret_line);
}
