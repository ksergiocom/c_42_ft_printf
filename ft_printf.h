/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:05:58 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/25 01:25:44 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# include "libft.h"

int	print_hex(long n, int caps);
int	print_ptr(unsigned long n);
int	print_chr(char c);
int	print_str(char *str);
int	print_uint(unsigned int i);
int	print_int(int i);
int	ft_printf(const char *str, ...);

#endif
