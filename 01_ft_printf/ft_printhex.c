/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/30 17:57:48 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenhex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len ++;
	}
	return (num);
}

int	ft_printhex(unsigned long long num, char *format, int base)
{
	if (num >= base)
	{
		ft_printhex(num / base, format, base);
		ft_printhex(num % base, format, base);
	}
	else if (num < base)
		ft_putchar_fd(format[num], 1);
	return (ft_lenhex(num));
}
