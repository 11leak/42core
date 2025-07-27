/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:58:27 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/26 14:26:31 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(argv[1]));
	return (0);
}
