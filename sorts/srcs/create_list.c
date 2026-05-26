/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:41:38 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/26 11:12:54 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

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
		new_node = malloc(sizeof(t_list));
		if (!new_node)
			return (free_list(head), NULL);
		new_node->content = &arr[i];
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		i++;
	}
	return (head);
}
