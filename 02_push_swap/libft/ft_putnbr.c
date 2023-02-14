/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:46:34 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/02/14 16:55:16 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long int num)
{
	char tmp;

	if (num < 0)
	{
		putchar('-');
		num = -num; 
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		num %= 10;
	}
	if (num <= 9)
	{
		tmp = num + 48;
		ft_putchar(&tmp);		
	}
}
