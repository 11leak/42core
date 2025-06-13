/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:41:04 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/12 14:48:04 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s1[i] && s2[i] && n > 0)
	{
		if (s1[i] < s2[i])
			res = s1[i] - s2[i];
		if (s1[i] > s2[i])
			res = s1[i] - s2[i];
		i++;
		n--;
	}
	return (res);
}
