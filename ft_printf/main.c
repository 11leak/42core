/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:22:19 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/12 01:15:14 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	main()
{
	// char c = 'a';
	// char *s = "test";
	// int i = 187;
	// unsigned int u = 4294967295;
	// char* p = "pointer";

	// ft_printf("----- Own Solution -----\n");
	// ft_printf("Length: %d\n", ft_printf("Char:\t%c\nStr:\t%s\nInt:\t%i\nDec:\t%d\nUI:\t%u\np:\t%p\nx:\t%x\nX:\t%X\nper: %%\n", c, s, i, i, u, p));
	// ft_printf("%s", (char *)NULL);
	// printf("%s", (char *)NULL);
	// printf("----- Printf Solution -----\n");
	// printf("Length: %d\n", printf("Char:\t%c\nStr:\t%s\nInt:\t%i\nDec:\t%d\nUI:\t%u\np:\t%p\nx:\t%x\nX:\t%X\nper:\t%%\nNULL:\t%s\n", c, s, i, i, u, &p, 0xFF, 255, (char *)NULL));
	// ft_printf("%d\n", ft_printf("%x\n", 2000));
	// printf("%d\n", printf("%x\n", 2000));
	char *str = "test";
	ft_printf("%p\n", str);
	printf("%p\n", str);
}

