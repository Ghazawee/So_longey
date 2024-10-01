/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:22:59 by mshaheen          #+#    #+#             */
/*   Updated: 2024/10/01 11:00:38 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
	{
		write(2, "Map not found\n", 14);
		exit(1);
	}
	else if (i == 2)
	{
		write(2, "Inavlid Map, Map is empty\n", 26);
		exit(1);
	}
	else if (i == 3)
	{
		write(2, "Unreachable collectable or exit\n", 32);
		exit(1);
	}
}
