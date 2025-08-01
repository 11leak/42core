/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/08/01 17:07:25 by dwotsche         ###   ########.fr       */
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
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
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

	if (!rest || !*rest || !line)
		return (0);
	nl_index = ft_strchr_index(*rest, 10);
	if (nl_index != -1)
	{
		*line = malloc(nl_index + 2);
		if (!*line)
			return (0);
		ft_strlcpy(*line, *rest, nl_index + 2);
		tmp = ft_strdup(*rest + nl_index + 1);
		if (!tmp)
		{
			free(*line);
			*line = NULL;
			return (0);
		}
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
	char		*new_rest;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			if (rest)
			{
				free(rest);
				rest = NULL;
			}
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!rest)
		{
			rest = ft_strdup(buffer);
			if (!rest)
				return (free(buffer), NULL);
		}
		else
		{
			new_rest = ft_strjoin_and_free(rest, buffer);
			if (!new_rest)
				return (free(buffer), free(rest), rest = NULL, NULL);
			rest = new_rest;
		}
		if (ft_nl_check(&rest, &line) == 1)
			return (free(buffer), line);
	}
	free(buffer);
	if (rest && *rest)
	{
		if (ft_nl_check(&rest, &line))
			return (line);
		return (line = ft_strdup(rest), free(rest), rest = NULL, line);
	}
	if (rest)
	{
		free(rest);
		rest = NULL;
	}
	return (NULL);
}
