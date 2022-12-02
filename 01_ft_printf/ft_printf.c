/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:49:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 19:13:11 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	check_arg(va_list args, char arg, int *count)
{
	if (arg == 'i' || arg == 'd') {
		//int test = va_arg(args, int);
		//printf("Hellowwwwwww %d\n", test);
		ft_printbase(va_arg(args, int), "0123456789", 10, count);
	}
	else if (arg == 'c' )
		ft_printchar(va_arg(args, int), count);
	else if (arg == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (arg == '%')
		ft_printchar('%', count);
	else if (arg == 'p')
		ft_printptr(va_arg(args, unsigned long long), count);
	else if (arg == 'x')
		ft_printbase(va_arg(args, unsigned long long),
			"0123456789abcdef", 16, count);
	else if (arg == 'X')
		ft_printbase(va_arg(args, unsigned long long), 
			"0123456789ABCDEF", 16, count);
	if (arg == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), count);
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
			check_arg(args, format[i + 1], &len);
			i ++;
		}
		else
			ft_printchar(format[i], &len);
		i ++;
	}
	va_end(args);
	return (len);
}
/*
int main (int ac, char **av) {
	(void) ac;
	//(void) ac;
	//printf("Hello\n");
	//printf("\nLEN %d\n", ft_printf("%d", -200000));
	printf("Carac [%d]", ft_printf("%d", ft_atoi(av[1])));
	//printf("%d\n", ft_printf("%X\n", ft_atoi(av[1])));
	return (0);
}*/
