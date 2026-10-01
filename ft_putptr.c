/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:59:14 by frgonzal          #+#    #+#             */
/*   Updated: 2026/10/01 21:45:57 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr)
{
	if(!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	return (ft_putstr("0x") + ft_putnbr((long) ptr,"0123456789abcdef"));
}
