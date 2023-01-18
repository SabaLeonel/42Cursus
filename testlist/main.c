/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaba-qu <leonel.sabaquezada@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:56:57 by lsaba-qu          #+#    #+#             */
/*   Updated: 2023/01/18 14:01:14 by lsaba-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_last(t_list *liste)
{
	t_list *tmp;
	t_list *last;

	tmp = liste;
	last = NULL;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		last = tmp;
	}
	return last;
}

void ft_add_back(t_list **liste, int num)
{
	t_list *tmp;
	t_list *last;
	
	tmp = malloc(sizeof(t_list));
	last = ft_last(*liste);
	if (tmp)
	{
		if (*liste == NULL)
		{
			tmp->data = num;
			tmp->next = *liste;
			*liste = tmp;
		}
		else
		{
			tmp->data = num;
			tmp->next = NULL;
			last->next = tmp;
		}
	}

}


void ft_add_front(t_list **liste, int num)
{
	t_list *tmp;
	
	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = num;
		tmp->next = *liste;
		*liste = tmp;
	}
}

void print_list(t_list *liste)
{
	t_list *tmp;

	tmp = liste;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int main (void)
{
	t_list	*liste;

	liste = NULL;
	ft_add_back(&liste, 1);
	ft_add_back(&liste, 2);
	ft_add_back(&liste, 3);
	ft_add_back(&liste, 4);
	ft_add_back(&liste, 5);
	
	print_list(liste);
	return (0);
}