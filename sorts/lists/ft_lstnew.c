/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:23:04 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/27 14:04:02 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

t_list	*ft_lstnew(int content)
{
	t_list	*box;

	box = (t_list *)malloc(sizeof(t_list));
	if (!box)
		return (NULL);
	box->content = content;
	box->next = NULL;
	return (box);
}
