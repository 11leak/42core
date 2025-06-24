/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:26:05 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/23 13:44:14 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret_str;

	ret_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ret_str[i] = (*f)(i, s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
