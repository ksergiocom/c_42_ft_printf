/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:05:58 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/26 17:39:14 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# include "libft.h"

int		print_hex(unsigned int n, int caps);
int		print_ptr(unsigned long n);
int		print_chr(char c);
int		print_str(char *str);
int		print_uint(unsigned int i);
int		print_int(int i);
int		get_hex_length(unsigned int n);
int		get_uhex_length(unsigned long n);
int		get_uint_length(unsigned int n);
void	ft_putunbr_fd(unsigned int n, int fd);
int		ft_printf(const char *str, ...);

#endif
