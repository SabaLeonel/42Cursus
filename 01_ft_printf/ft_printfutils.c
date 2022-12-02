/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:10:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/30 19:58:25 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int num)
{
	int		i;
	char	*tab;

	i = 0;
	tab = ft_itoa(num);
	i = ft_printstr(tab);
	free (tab);
	return (i);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	ft_printchar('%');
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i ++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int num)
{
	int		i;
	char	*tab;

	i = 0;
	if (num)
		i += write(1, "0", 1);
	else
	{	
		tab = ft_itoa(num);
		i += ft_printstr(tab);
		free (tab);
	}
	return (i);
}
