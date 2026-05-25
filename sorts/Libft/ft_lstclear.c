/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:17:32 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/30 16:02:36 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cleaner;
	t_list	*next;

	if (!lst || !del)
		return ;
	cleaner = *lst;
	while (cleaner)
	{
		next = cleaner->next;
		(*del)((*cleaner).content);
		free(cleaner);
		cleaner = next;
	}
	*lst = NULL;
}
