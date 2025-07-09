/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:12:08 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/09 11:29:22 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
	return (len_nbr);
}
