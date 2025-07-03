/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:48:31 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/17 14:02:42 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len_s + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len_s + 1);
	return (ptr);
}
