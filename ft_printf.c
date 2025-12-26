/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:04:07 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/25 01:25:20 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_swap(const char *str, va_list list_args, int *bytes)
{
	if (*str == '%')
		*bytes += print_chr('%');
	if (*str == 'c')
		*bytes += print_chr(va_arg(list_args, int));
	else if (*str == 's')
		*bytes += print_str(va_arg(list_args, char *));
	else if (*str == 'i' || *str == 'd')
		*bytes += print_int(va_arg(list_args, int));
	else if (*str == 'u')
		*bytes += print_uint(va_arg(list_args, unsigned int));
	else if (*str == 'x')
		*bytes += print_hex(va_arg(list_args, int), 0);
	else if (*str == 'X')
		*bytes += print_hex(va_arg(list_args, int), 1);
	else if (*str == 'p')
		*bytes += print_ptr((unsigned long) va_arg(list_args, void *));
}

int	ft_printf(const char *str, ...)
{
	va_list	list_args;
	int		bytes;

	bytes = 0;
	va_start(list_args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			bytes++;
		}
		else
		{
			str++;
			flag_swap(str, list_args, &bytes);
		}
		str++;
	}
	va_end(list_args);
	return (bytes);
}
