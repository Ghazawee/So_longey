/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:24:47 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/09 10:31:55 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, f);
	while (*f != '\0')
	{
		if (*f == '%')
		{
			f++;
			len += dicases(*f, ap);
		}
		else
			len += ft_putchar(*f);
		f++;
	}
	va_end(ap);
	return (len);
}
