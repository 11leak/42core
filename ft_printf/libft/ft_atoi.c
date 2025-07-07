/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:41:58 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/07 16:09:02 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_whitespace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	is_negative;

	i = 0;
	res = 0;
	is_negative = 1;
	while (ft_is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative = -is_negative;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = ((res * 10) + (nptr[i] - 48));
		i++;
	}
	return (res * is_negative);
}
