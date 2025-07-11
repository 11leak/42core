/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:50:04 by dwotsche          #+#    #+#             */
/*   Updated: 2025/07/12 01:11:34 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_print_value(char c, va_list args);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putnbr_id(int nbr);
int	ft_putptr(void *ptr);

#endif
