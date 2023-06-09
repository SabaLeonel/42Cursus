typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr;
	t_list *prev;
	t_list *tmp;

	while (cmp((*begin_list)->data, data_ref) == 0)
	{
		prev = *begin_list;
		*begin_list = (*begin_list)->next;
		free(prev->data);
		free(prev);
	}
	prev = (*begin_list);
	curr = (*begin_list)->next;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
		{
			prev->next = curr->next;
			tmp = curr;
			curr = curr->next;
			free(tmp->data);
			free(tmp);
		}
		prev = curr;
		curr = curr->next;
	}
}
