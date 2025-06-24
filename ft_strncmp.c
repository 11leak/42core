/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:41:04 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/16 16:40:31 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned const char	*p_s1;
	unsigned const char	*p_s2;

	i = 0;
	p_s1 = (unsigned const char *)s1;
	p_s2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		if (p_s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
