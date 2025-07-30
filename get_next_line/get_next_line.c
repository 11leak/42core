/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/30 16:40:53 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1. get_next_line call
// rest leer
// buffer leer
// line leer
// 2. buffer liest gibt an rest
// es wird in rest geschaut ob sich ein \n befindet
// wenn ja: in line speichern und zurückgeben
// wenn nein: wieder buffer liest und addiert zu rest dazu
// bis ende

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*res;
	size_t	len = ft_strlen(s1) + ft_strlen(s2);

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	free(s1);
	return (res);
}

int	ft_nl_check(char **rest, char **line)
{
	int		nl_index;
	char	*tmp;

	nl_index = ft_strchr_index(*rest, 10);
	if (nl_index != -1)
	{
		*line = malloc(nl_index + 2);
		if (!*line)
			return (0);
		ft_strlcpy(*line, *rest, nl_index + 2);
		tmp = ft_strdup(*rest + nl_index + 1);
		free(*rest);
		*rest = tmp;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			read_bytes;

	line = NULL;
	read_bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!rest)
			rest = ft_strdup(buffer);
		else
			rest = ft_strjoin_and_free(rest, buffer);
		if (ft_nl_check(&rest, &line) == 1)
		{
			free(buffer);
			return (line);
		}
	}
	free(buffer);
	if (rest && *rest)
	{
		if (ft_nl_check(&rest, &line))
			return (line);
		line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (line);
	}
	free(rest);
	rest = NULL;
	return (NULL);
}
