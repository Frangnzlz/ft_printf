/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 21:34:14 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/02 19:54:33 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putsigned(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putstr("%"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		leng;
	int		i;

	va_start(args, format);
	if (!format)
		return (-1);
	leng = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			leng += ft_check_conversion(format[i], args);
		}
		else
			leng += ft_putchar(format[i]);
		if (format[i])
			i++;
	}
	va_end(args);
	return (leng);
}
/*
int	main(void)
{
	ft_printf("char: %c\n", 'A');
	ft_printf("str: %s\n", "hola");
	ft_printf("ptr: %p\n", (void *)0x1234);
	ft_printf("int: %d %i\n", -42, 42);
	ft_printf("uint: %u\n", 4294967295u);
	ft_printf("hex: %x %X\n", -200, 255);
	ft_printf("percent: %%\n");
	printf("char: %c\n", 'A');
	printf("str: %s\n", "hola");
	printf("ptr: %p\n", (void *)0x1234);
	printf("int: %d %i\n", -42, 42);
	printf("uint: %u\n", 4294967295u);
	printf("hex: %x %X\n", -200, 255);
	printf("percent: %%\n");
	return (0);
}
*/