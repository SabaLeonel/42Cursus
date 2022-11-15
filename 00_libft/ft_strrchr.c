/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:36:27 by lsaba-qu          #+#    #+#             */
/*   Updated: 2022/11/01 11:44:12 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cherche;
	char	*tab;

	i = ft_strlen(s);
	cherche = c;
	tab = (char *)s;
	while (i >= 0)
	{
		if (tab[i] == cherche)
			return (&tab[i]);
		i--;
	}
	if (cherche == 0)
		return (&tab[i]);
	return (NULL);
}
