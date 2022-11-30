/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:07:58 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/28 18:00:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenptr(unsigned long num)
{
	int	i;

	i = 0;
	if (!num)
		return (0);
	while (num != 0)
	{
		num /= 16;
		i ++;
	}
	return (i);
}

void	ft_putptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else 
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}

int	ft_printptr(unsigned long long num)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (num == 0)
		len += write(1, "0", 1);
	else
	{		
		ft_putptr(num);
		len += ft_lenptr(num);
	}
	return (len);
}
