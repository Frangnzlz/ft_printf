/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:15:47 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/01 21:54:37 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putsigned(long *i)
{
	int put;

	put = 0;
	if (*i < 0)
	{
		*i *= -1;
		put = (write(1, "-", 1));
	}
	return (put + ft_putnbr((unsigned long)*i, "0123456789"));
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
	base_len = ft_strlen(base);
	if(i >= base_len)
		leng += ft_putnbr(i / base_len, base);
	write(1, &base[i % base_len], 1);
	return (1 + leng);
}

int main()
{
	long s;

	s  = -200;
	
	printf(" :%i\n",ft_putsign(&s));
	printf(" :%i",printf("%i", -200));
}