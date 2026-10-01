/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgonzal <frgonzal@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:36:34 by frgonzal          #+#    #+#             */
/*   Updated: 2026/09/30 20:47:17 by frgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putstr(char *s)
{
	if(!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}
