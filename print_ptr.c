/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:03:53 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/26 17:17:38 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_uhex_length(unsigned long n)
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

int	print_ptr(unsigned long n)
{
	char	*hex_digits;
	char	*new_str;
	int		length;

	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex_digits = "0123456789abcdef";
	length = get_uhex_length(n);
	new_str = ft_calloc(length + 1, sizeof(char));
	while (n)
	{
		new_str[length - 1] = hex_digits[n % 16];
		n = n / 16;
		length--;
	}
	print_str("0x");
	length = (print_str(new_str) + 2);
	free(new_str);
	return (length);
}
