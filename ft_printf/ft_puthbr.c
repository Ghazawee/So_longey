/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:42:53 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/08 08:27:16 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthbr(unsigned long long n, char g)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthbr(n / 16, g);
		count += ft_puthbr(n % 16, g);
	}
	else
	{
		if (n >= 10 && n <= 15)
		{
			if (g == 'X')
				count += ft_putchar((n - 10) + 'A');
			else if (g == 'x')
				count += ft_putchar((n - 10) + 'a');
		}
		else if (n <= 9)
			count += ft_putchar(n + '0');
	}
	return (count);
}
