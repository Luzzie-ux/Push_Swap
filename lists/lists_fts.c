/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:22:25 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/08 13:24:51 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*box;

	box = (t_list *)malloc(sizeof(t_list));
	if (!box)
		return (free_list(box), NULL);
	box->data = content;
	box->next = NULL;
	box->prev = NULL;
	box->rank = -1;
	return (box);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while ((*lst).next)
		lst = (*lst).next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*walker;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	walker = *lst;
	while ((*walker).next)
		walker = (*walker).next;
	walker->next = new;
	walker->next->prev = walker;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	(*new).next = *lst;
	*lst = new;
}
