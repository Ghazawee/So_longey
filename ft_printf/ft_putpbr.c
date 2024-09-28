/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:52:54 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/08 08:27:04 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpbr(void *n)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthbr((unsigned long long)n, 'x');
	return (count);
}
