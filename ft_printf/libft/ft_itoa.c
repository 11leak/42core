/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:22:33 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/10 13:36:11 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_cases(int n)
{
	char	*ret;

	if (n == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		if (!ret)
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	return (0);
}

int	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_extension(int nbrs, int nbr, int n)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * nbrs + 1);
	if (!ret)
		return (NULL);
	ret[nbrs] = '\0';
	nbrs--;
	if (ft_is_negative(n))
	{
		ret[0] = '-';
		nbr = n * (-1);
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		ret[nbrs--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*cases;
	int		nbrs;
	int		nbr;

	cases = ft_check_cases(n);
	if (cases)
		return (cases);
	nbrs = 0;
	if (ft_is_negative(n))
	{
		nbrs++;
		nbr = n * (-1);
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		nbrs++;
	}
	return (ft_extension(nbrs, nbr, n));
}
