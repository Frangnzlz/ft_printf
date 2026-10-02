/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:03:32 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/02 19:03:12 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(unsigned long i, char *base);
int	ft_strlen(char *s);
int	ft_putstr(char *s);
int	ft_putchar(char s);
int	ft_putsigned(long i);
int	ft_putptr(void *ptr);

#endif
