/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:39:25 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/12 01:21:46 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_extension_putnbr_fd(int n, char *str, int i, int fd)
{
	while (n > 0)
	{
		str[i++] = n % 10 + 48;
		n = n / 10;
	}
	i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		write(fd, &str[i--], 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	str[11];

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_extension_putnbr_fd(n, str, i, fd);
}
