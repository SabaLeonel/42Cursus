/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:10:08 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/12/02 19:13:34 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int	ft_printnb(int num)
{
	int		i;
	char	*tab;

	i = 1;
	tab = ft_itoa(num);
	i = ft_printstr(tab);
	free (tab);
	return (i);
}*/

void	ft_printchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}
/*
int	ft_printpercent(void)
{
	ft_printchar('%');
	return (1);
}
*/
void	ft_printstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		ft_printstr("(null)", count);
	while (str[i])
	{
		ft_printchar(str[i], count);
		i ++;
	}
}

void	ft_print_unsigned(unsigned int num, int *count)
{
	int		i;
	char	*tab;

	i = 0;
	if (num == 0)
		ft_printchar('0', count);
	else
	{	
		tab = ft_itoa(num);
		ft_printstr(tab, count);
		free (tab);
	}
}
