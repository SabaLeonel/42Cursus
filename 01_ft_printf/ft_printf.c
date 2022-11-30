/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/30 17:57:30 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(va_list args, char arg)
{
	int		num;
	char	*basehex;
	char	*basehexmaj;

	num = 0;
	basehex = "0123456789abcdef";
	basehexmaj = "0123456789ABCDEF";
	if (arg == 'i' || arg == 'd')
		num += ft_printhex(va_arg(args, unsigned long long), "0123456789", 10);
	else if (arg == 'c' )
		num += ft_printchar(va_arg(args, int));
	else if (arg == 's')
		num += ft_printstr(va_arg(args, char *));
	else if (arg == '%')
		num += ft_printpercent();
	else if (arg == 'p')
		num += ft_printptr(va_arg(args, unsigned long long));
	else if (arg == 'x')
		num += ft_printhex(va_arg(args, unsigned long long), basehex, 16);
	else if (arg == 'X')
		num += ft_printhex(va_arg(args, unsigned long long), basehexmaj, 16);
	if (arg == 'u')
		num += ft_print_unsigned(va_arg(args, unsigned int));
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
/*
int main(int ac, char **av) {
	(void) ac;
	ft_printf("salut %X", ft_atoi(av[1]));
	return (0);
}
*/