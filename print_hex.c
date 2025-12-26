/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:03:53 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/26 17:16:30 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_length(unsigned int n)
{
	int	length;

	length = 1;
	while (n > 15)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

int	print_hex(unsigned int n, int caps)
{
	char	*hex_digits;
	char	*new_str;
	int		length;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	hex_digits = "0123456789abcdef";
	length = get_hex_length(n);
	new_str = ft_calloc(length + 1, sizeof(char));
	while (n)
	{
		new_str[length - 1] = hex_digits[n % 16];
		if (caps)
			new_str[length - 1] = ft_toupper(new_str[length - 1]);
		n = n / 16;
		length--;
	}
	print_str(new_str);
	length = ft_strlen(new_str);
	free(new_str);
	return (length);
}
