/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:15:47 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/01 20:14:47 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int ft_putsign(long *i)
{
	if (*i < 0)
	{
		*i *= -1;
		return (write(1, "-", 1));
	}
	return (0);
}

int ft_strlen(char *s)
{
	char *fs;

	fs = s;
	while (*fs)
		fs++;
	return (fs - s);
}

int ft_putnbr(unsigned long i, char *base)
{
	int leng;
	unsigned long base_len;

	leng = 0;
	if (*base == '-')
	{
//		leng = ft_putsign(&i);
		base++;
	}
	base_len = ft_strlen(base);
	if(i >= base_len)
		leng += ft_putnbr(i / base_len, base);
	write(1, &base[i % base_len], 1);
	return (1 + leng);
}

