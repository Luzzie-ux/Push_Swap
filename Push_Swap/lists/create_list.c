/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:41:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/11 11:54:40 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_list(t_list *head)
{
	t_list	*temp;

	if (!head)
		return ;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_list	*create_list(int *arr, int size)
{
	int		i;
	t_list	*head;
	t_list	*tail;
	t_list	*new_node;

	i = 0;
	head = NULL;
	tail = NULL;
	while (i < size)
	{
		new_node = ft_lstnew(arr[i++]);
		if (!head)
			head = new_node;
		else
			ft_lstadd_back(&tail, new_node);
		tail = new_node;
	}
	return (head);
}
