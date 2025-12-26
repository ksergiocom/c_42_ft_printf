/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:03:53 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/25 01:25:27 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(long n, int caps)
{
	char	*hex_digits;
	char	selected;
	int		bytes;

	bytes = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		bytes += print_hex(n / 16, caps);
	selected = hex_digits[n % 16];
	if (caps)
		selected = ft_toupper(selected);
	ft_putchar_fd(selected, 1);
	bytes++;
	return (bytes);
}
