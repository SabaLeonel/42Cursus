/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/25 23:34:17 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(va_list args, char arg)
{
	int	num;

	num = 0;
	if (arg == 'i' || arg == 'd')
		num += ft_printnb(va_arg(args, int));
	else if (arg == 'c' )
		num += ft_printchar(va_arg(args, int));
	else if (arg == 's')
		num += ft_printstr(va_arg(args, char *));
	else if (arg == '%')
		num += ft_printpercent();
/*	if (arg == 'x' || arg == 'X')
		num += ft_printhex(va_arg(args, unsigned long long), arg);
	if (arg == 'p')
	{
		num += write(1, "0x", 2);
		num += ft_printptr(va_arg(args, unsigned long long));
	}
	if (arg == 'u')
		num += ft_print_unsigned(va_arg(args, unsigned int));
*/
	return (num);
}		

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_arg(args, format[i + 1]);
			i ++;
		}
		else
			len += ft_printchar(format[i]);
		i ++;
	}
	va_end(args);
	return (len);
}
