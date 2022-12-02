/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:07:58 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 19:11:44 by lsaba-qu         ###   ########.fr       */
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

void	ft_putptr(unsigned long num, int *count)
{
	if (num >= 16)
	{
		ft_putptr(num / 16, count);
		ft_putptr(num % 16, count);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0', count);
		else
			ft_printchar(num - 10 + 'a', count);
	}
}

void	ft_printptr(unsigned long long num, int *count)
{
	int	len;

	len = 0;
	ft_printstr("0x", count);
	if (num == 0)
		ft_printchar('0', count);
	else	
		ft_putptr(num, count);
}
