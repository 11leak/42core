/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/29 13:50:30 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr_index(const char *s, int c)
{
	int	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1 = ft_strlen(s1);
	size_t	len_s2 = ft_strlen(s2);
	char	*ptr = malloc(len_s1 + len_s2 + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcpy(ptr + len_s1, s2, len_s2 + 1);
	return (ptr);
}

static char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	int			found_nl;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		found_nl = ft_strchr_index(rest, '\n');
		if (found_nl != -1)
		{
			line = malloc(found_nl + 2);
			if (!line)
				return (NULL);
			ft_strlcpy(line, rest, found_nl + 2);
			tmp = ft_strdup(rest + found_nl + 1);
			free(rest);
			rest = tmp;
			return (line);
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buffer[read_bytes] = '\0';
		rest = ft_strjoin_and_free(rest, buffer);
	}
	if (rest && *rest)
	{
		line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (line);
	}
	free(rest);
	rest = NULL;
	return (NULL);
}

