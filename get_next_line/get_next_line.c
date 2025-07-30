/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/30 13:03:37 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin_and_free(char *s1, char *s2);

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
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	return (ptr);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
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
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;

	line = NULL;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		if (!rest)
			rest = ft_strdup(buffer);
		else
			rest = ft_strjoin_and_free(rest, buffer);
		if (ft_nl_check(&rest, &line) == 1)
			return (line);
		// read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (rest && *rest)
	{
		if (ft_nl_check(&rest, &line))
			return (line);
		line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (line);
	}
	return (NULL);
}
