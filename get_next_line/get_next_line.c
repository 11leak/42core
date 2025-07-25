/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:01:06 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/25 16:59:06 by dwotsche         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest;
	char		*line;
	char*		found_nl;
	int			read_bytes;

	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (!rest)
			rest = ft_strdup(buffer);
		ft_strlcat(rest, buffer, ft_strlen(buffer));
		if ((found_nl = ft_strchr(rest, '\n')) != NULL)
		{
			ft_strlcpy(line, rest, found_nl);
			return(line);
		}
	}
}
