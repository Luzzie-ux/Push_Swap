/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:54:22 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 14:04:18 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

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
}
