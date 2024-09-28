/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:17:49 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/09 10:31:04 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dicases(const char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		count += ft_putubr(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_puthbr(va_arg(ap, unsigned int), type);
	else if (type == 'p')
		count += ft_putpbr(va_arg(ap, void *));
	else if (type == '%')
		count += ft_putchar('%');
	return (count);
}
