/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:21:07 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/07 16:09:26 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_value(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		len = ft_putstr_fd(va_arg(args, char*), 1);
	// if (c == 'p')
		// void * pointer - (hexadecimal format)
	// if (c == 'd')
		// p
	// if (c == 'i')
	// 	// integer
	// if (c == 'u')
	// 	// unsigned decimal
	// if (c == 'x')
	// 	// hexadecimal (base 16) lowercase
	// if (c == 'X')
	// 	// hexadecimal (base 16) uppercase
	// if (c == '%')
	// 	// percent sign
	return (len);
}

int	ft_printf(const char* s, ...)
{
	int		i;
	int		len_s;
	va_list	args;

	i = 0;
	len_s = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len_s += ft_print_value(s[i + 1], args);
			i++;
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (len_s);
}
