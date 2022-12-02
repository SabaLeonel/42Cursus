/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:08:05 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 19:12:26 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
int	ft_lenhex(int num, int base)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= base;
		len ++;
	}
	return (len);
}
*/
void	ft_printbase(int num, char *format, int base, int *count)
{
	//printf("Num -> %d\n", num);
	if (num < 0) {
		ft_printchar('-', count);
		ft_printbase((num * -1), format, base, count);
	}
	else if (num >= (int)base)
	{
		ft_printbase(num / base, format, base, count);
		ft_printbase(num % base, format, base, count);
	}
	else if (num < (int)base)
		ft_printchar(format[num], count);
}
