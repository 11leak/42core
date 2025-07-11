/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:21:07 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/11 14:28:14 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_value(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	// else if (c == 'p')
		// void * pointer - (hexadecimal format)
	else if (c == 'd')
		len = ft_putnbr_id(va_arg(args, int));
	else if (c == 'i')
		len = ft_putnbr_id(va_arg(args, int));
	else if (c == 'u')
		len = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_puthex_fdx(va_arg(args, unsigned int));
	else if (c == 'X')
		len = ft_puthex_fdxx(va_arg(args, unsigned int));
	else if (c == '%')
		len = ft_putchar_fd('%', 1);
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
		{
			ft_putchar_fd(s[i], 1);
			len_s++;
		}
		i++;
	}
	va_end(args);
	return (len_s);
}
