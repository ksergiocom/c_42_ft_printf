/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekhudol <sekhudol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:43:28 by sekhudol          #+#    #+#             */
/*   Updated: 2025/12/25 00:28:13 by sekhudol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int	print_uint(unsigned int i)
{
	ft_putunbr_fd(i, 1);
	return (ft_strlen(ft_itoa(i)));
}
