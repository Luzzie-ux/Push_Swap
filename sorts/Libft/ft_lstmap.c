/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:54:15 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/30 16:05:48 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*nlist;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			(*del)(content);
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, node);
		lst = (*lst).next;
	}
	return (nlist);
}
