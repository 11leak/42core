/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:35:19 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/18 14:14:50 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_ptr;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	len_ptr = ft_strlen(s1) + ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc((len_ptr + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcat(ptr + len_s1, s2, len_s2 + 1);
	ptr[len_ptr + 1] = '\0';
	return (ptr);
}
