/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:57:56 by mshaheen          #+#    #+#             */
/*   Updated: 2024/07/08 08:26:21 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *type, ...);
int	dicases(const char type, va_list ap);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_puthbr(unsigned long long n, char g);
int	ft_putubr(unsigned int n);
int	ft_putpbr(void *n);
int	ft_putstr(char *s);

#endif