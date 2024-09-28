/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putubr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:50:32 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/08 08:26:28 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putubr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putubr(n / 10);
		count += ft_putubr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
