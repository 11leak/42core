/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:58:27 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/30 17:04:30 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);


	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);  // kein \n hinzufügen, steht evtl. schon in der Zeile
		free(line);
	}
	close(fd);
	return (0);
}
