/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 21:34:14 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/01 22:15:00 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(char c)
{
	if (c == 'c')
		return (ft_putstr(&c));
	else if (c == 's')
		return (ft_putstr(&c));
	else if (c == 'p')
		return (ft_putptr(&c));
	else if (c == 'd' || c == 'i')
		return (ft_putsigned(1));
	else if (c == 'u')
		return (ft_putnbr(1, "0123456789"));
	else if (c == 'x')
		return (ft_putnbr(1, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr(1, "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putstr("%"));
	else
		return (-1);
}



int ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format)
}