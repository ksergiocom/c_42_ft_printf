/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:03:53 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/25 01:00:39 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long n)
{
	char	*hex_digits;
	char	selected;
	int		bytes;

	if (!n)
	{
		ft_putstr_fd("(nil)",1);
		return (5);
	}
	bytes = 2;
	print_str("0x");
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		bytes += print_ptr(n / 16);
	selected = hex_digits[n % 16];
	ft_putchar_fd(selected, 1);
	bytes++;
	return (bytes);
}
