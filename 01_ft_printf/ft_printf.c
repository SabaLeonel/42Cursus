/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/24 17:00:40 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int	check_arg(va_list args, char arg)
{
	int num;
	
	i = 0;
	if (arg == 'i' || arg == 'd')
		num += ft_putnbr_fd(va_arg(args), int));
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			len += check_arg(args, format[i + 1]);
			i ++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i ++;
	}
}