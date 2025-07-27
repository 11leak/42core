/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/27 14:48:59 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2);

// 1. get_next_line call
// rest leer
// buffer leer
// line leer
// 2. buffer liest gibt an rest
// es wird in rest geschaut ob sich ein \n befindet
// wenn ja: in line speichern und zurückgeben
// wenn nein: wieder buffer liest und addiert zu rest dazu
// bis ende

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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest;
	char		*line;
	int			found_nl;
	int			read_bytes;

	line = NULL;
	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (!rest)
			rest = ft_strdup(buffer);
		ft_strlcat(rest, buffer, ft_strlen(buffer));
		if ((found_nl = ft_strchr(rest, 10)) != -1)
		{
			ft_strlcpy(line, rest, found_nl);
			return (line);
		}
	}
	return (NULL);
}
