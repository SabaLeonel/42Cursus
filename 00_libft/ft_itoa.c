/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:47 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/16 17:05:05 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  long int	ft_len(int num)
{
	int i;

	i = 0;
	if (num <= 0)
		return (1);
	while (num != 0)
	{
		
		i ++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*tab;
	long int	i;

	i = ft_len(n);
	tab = malloc((sizeof(char) * i) + 1);
	if (!tab)
		return (NULL);
	tab[i--] = '\0';
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
	{
		n *= -1;
		tab[0] = '-';
	}
	
	while (n > 0)
	{
		tab[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (tab);	
}
