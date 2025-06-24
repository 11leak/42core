/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:00:23 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/18 14:15:14 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		f;
	int		b;
	int		len;
	char	*ptr;

	f = 0;
	while (s1[f] && ft_is_in_set(s1[f], set))
		f++;
	b = ft_strlen(s1);
	while (b > f && ft_is_in_set(s1[b - 1], set))
		b--;
	len = b - f;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[f], len + 1);
	return (ptr);
}
