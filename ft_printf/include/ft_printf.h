/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:26:25 by fyardimc          #+#    #+#             */
/*   Updated: 2022/08/21 10:49:55 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX1 "0123456789abcdef"
# define HEX2 "0123456789ABCDEF"
# define DEC "0123456789"

int		ft_printf(const char *firstarg, ...);
//ptr-hex-unsigned-signed
int		ft_put_num_base(int n, const char *base);
int		ft_put_ux_num(unsigned long long n, const char *base, size_t base_len);
int		ft_put_ptr(unsigned long long n, const char *base, size_t base_len);
//string-char
int		ft_put_char(char c);
int		ft_put_string(const char *str);
//funcs
size_t	ft_strlen(const char *s);

#endif