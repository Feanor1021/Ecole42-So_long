/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:56:17 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/21 10:50:36 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/include/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12323
# endif

char	*get_next_line(int fd);
char	*get_till_n(int fd, char *line);

char	*get_line(char *line);
char	*skip_next_n(char *line);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);

#endif