/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:58:27 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/29 16:57:15 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);  // kein \n hinzufügen, steht evtl. schon in der Zeile
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
