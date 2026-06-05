/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:12:40 by rodrpere          #+#    #+#             */
/*   Updated: 2026/06/05 09:45:22 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

void	simple(t_list	*a)
{
	int	i;
	int j;
	t_list	*t1;
	t_list	*t2;

	i = 0;
	t1 = a;
	while (i <  ft_lstsize(a))
	{
		j = i + 1;
		t2 = t1->next;
		while (j < ft_lstsize(a))
		{
			if (t1->content > t2->content)
				sa(t1);
			t2 = t2->next;
			j++;
		}
		t1 = t1->next;
		i++;
	}
}