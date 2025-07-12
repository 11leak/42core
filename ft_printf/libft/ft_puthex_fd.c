/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:50:04 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/12 02:16:11 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fdx(unsigned int nb)
{
	int		i;
	char	*hex;
	int		ret;
	char	prin[20];

	hex = "0123456789abcdef";
	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		prin[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	ret = i;
	i--;
	while (i >= 0)
	{
		write(1, &prin[i], 1);
		i--;
	}
	return (ret);
}

int	ft_puthex_uintptr(uintptr_t nb)
{
	int		i;
	char	*hex;
	int		ret;
	char	prin[20];

	hex = "0123456789abcdef";
	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	while (nb > 0)
	{
		prin[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	i--;
	ret = i;
	while (i >= 0)
	{
		write(1, &prin[i], 1);
		i--;
	}
	return (ret + 1);
}

int	ft_puthex_fdxx(unsigned int nb)
{
	int		i;
	char	*hex;
	int		ret;
	char	prin[20];

	hex = "0123456789ABCDEF";
	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		prin[i] = hex[nb % 16];
		nb /= 16;
		i++;
	}
	ret = i;
	i--;
	while (i >= 0)
	{
		write(1, &prin[i], 1);
		i--;
	}
	return (ret);
}
