/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 14:06:59 by rodrpere          #+#    #+#             */
/*   Updated: 2026/05/25 19:13:54 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorts.h"

t_tree	*new_node(void *content)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	if (!node)
		return (NULL);
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	insert(t_tree **root, int value)
{
	if (*root == NULL)
	{
		*root = new_node((void *)(long)value);
		return ;
	}
	if (value < (int)(long)(*root)->content)
		insert(&(*root)->left, value);
	else
		insert(&(*root)->right, value);
}

t_tree	*insertion(int *array, int size)
{
	t_tree	*root;

	root = NULL;
	for (int i = 0; i < size; i++)
		insert(&root, array[i]);
	return (root);
}

int	tree_size(t_tree *root)
{
	if (root == NULL)
		return (0);
	return (1 + tree_size(root->left) + tree_size(root->right));
}
