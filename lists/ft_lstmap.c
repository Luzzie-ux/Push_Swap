/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:54:15 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 14:10:10 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	t_list	*node;
	t_list	*nlist;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst)
	{
		content = (*f)((int)lst->content);
		node = ft_lstnew((long)content);
		if (!node)
		{
			(*del)((long)content);
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, node);
		lst = (*lst).next;
	}
	return (nlist);
}
