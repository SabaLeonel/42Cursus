/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:51:10 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/01 10:21:13 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cherche;
	char	*tab;

	i = 0;
	cherche = c;
	tab = (char *)s;
	while (tab[i])
	{
		if (tab[i] == cherche)
			return (&tab[i]);
		i++;
	}
	if (cherche == 0)
		return (&tab[i]);
	return (NULL);
}
