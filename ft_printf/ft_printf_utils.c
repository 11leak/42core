/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:12:08 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/10 13:41:00 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_extension(unsigned int nb, char *str, int i);

int	ft_putnbr_u(unsigned int nb)
{
	int		i;
	char	str[11];

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_extension(nb, str, i));
}

static int	ft_extension(unsigned int nb, char *str, int i)
{
	int	ret;

	ret = 0;
	while (nb > 0)
	{
		str[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	ret = i;
	i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		write(1, &str[i--], 1);
	}
	return (ret);
}

int	ft_putnbr_id(int nbr)
{
	int		len_nbr;
	char*	s;

	len_nbr = 0;
	s = ft_itoa(nbr);
	while (s[len_nbr])
	{
		ft_putchar_fd(s[len_nbr], 1);
		len_nbr++;
	}
	free (s);
	return (len_nbr);
}
