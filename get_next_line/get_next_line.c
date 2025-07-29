/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/29 14:50:12 by dwotsche         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_bytes;
	int			nl_index;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 1)
	{
		if (!rest)
			ft_strjoin_and_free(rest, buffer);
		else if (rest)
			ft_strlcat(rest, buffer, ft_strlen(buffer));
		if (ft_strchr_index(rest, 10))
		{
			nl_index = ft_strchr_index(rest, 10);
			ft_strlcpy(line, rest, nl_index);
			break ;
		}
	}
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	static char	*rest;
// 	char		buffer[BUFFER_SIZE + 1];
// 	char		*line;
// 	char		*tmp;
// 	int			found_nl;
// 	int			read_bytes;

// 	read_bytes = 1;
// 	while (read_bytes > 0)
// 	{
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		buffer[read_bytes] = '\0';
// 		if (!rest)
// 			rest = ft_strdup(buffer);
// 		else
// 			rest = ft_strjoin_and_free(rest, buffer);
// 		found_nl = ft_strchr_index(rest, '\n');
// 		if (found_nl != -1)
// 		{
// 			line = malloc(found_nl + 2);
// 			if (!line)
// 				return (NULL);
// 			ft_strlcpy(line, rest, found_nl + 2);
// 			tmp = ft_strdup(rest + found_nl + 1);
// 			free(rest);
// 			rest = tmp;
// 			return (line);
// 		}
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	if (rest && *rest)
// 	{
// 		line = ft_strdup(rest);
// 		free(rest);
// 		rest = NULL;
// 		return (line);
// 	}
// 	return (NULL);
// }
