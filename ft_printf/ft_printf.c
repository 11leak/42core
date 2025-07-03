/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:21:07 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/03 12:06:15 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_value(char c)
{
	if (c == 'c')
		// char
	if (c == 's')
		// string
	if (c == 'p')
		// void * pointer - (hexadecimal format)
	if (c == 'd')
		// decimal
	if (c == 'i')
		// integer
	if (c == 'u')
		// unsigned decimal
	if (c == 'x')
		// hexadecimal (base 16) lowercase
	if (c == 'X')
		// hexadecimal (base 16) uppercase
	if (c == '%')
		// percent sign
}

int	ft_printf(const char* s, ...)
{
	int	i;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_print_value(s[i + 1]);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
		}
		i++;
	}

}
