#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int content;
	struct s_list *prev;
	struct s_list *next;
	int rank;

} t_list;

void free_list(t_list *head)
{
	t_list *temp;

	if (!head)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

t_list *ft_lstnew(int content)
{
	t_list *box;

	box = (t_list *)malloc(sizeof(t_list));
	if (!box)
		return (free_list(box), NULL);
	box->content = content;
	box->next = NULL;
	box->prev = NULL;
	box->rank = -1;
	return (box);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *walker;

	if (!lst || !new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	walker = *lst;
	while ((*walker).next)
		walker = (*walker).next;
	walker->next = new;
	walker->next->prev = walker;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while ((*lst).next)
		lst = (*lst).next;
	return (lst);
}

int ft_lstsize(t_list *lst)
{
	int i;

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

t_list *create_list(int *arr, int size)
{
	int i;
	t_list *head;
	t_list *tail;
	t_list *new_node;

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

void	ra(t_list **stack_a)
{
	t_list	*tail;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tail = ft_lstlast(*stack_a);
	tail->prev->next = NULL;
	(*stack_a)->prev = tail;
	tail->next = *stack_a;
	tail->prev = NULL;
	(*stack_a) = tail;
}

void	sa(t_list **stack_a)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	if (ft_lstsize(*stack_a) < 2)
		return;
	head = (*stack_a);
	second = head->next;
	tail = second->next;

	(*stack_a) = second;
	second->prev = NULL;
	second->next = head;
	head->prev = second;
	head->next = tail;
	if (tail)
		tail->prev = head;
}

int ft_atoi(const char *nptr)
{
	long num;
	int sign;
	char *ptr;

	num = 0;
	sign = 1;
	if (!nptr)
		return (0);
	ptr = (char *)nptr;
	while (*ptr && !(*ptr >= '0' && *ptr <= '9') && *ptr != '-' && *ptr != '+')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr && !(*ptr >= '0' && *ptr <= '9'))
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = (num * 10) + (*ptr - '0');
		ptr++;
	}
	return (num * sign);
}

int		isorted(t_list *a)
{
	t_list	*temp = a;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	simple(t_list **a)
{
	int		count;

	if(!a)
		return ;
	count = 0;
	while (!isorted(*a))
	{
		count = 0;
		while (count < ft_lstsize(*a) - 1)
		{
			if ((*a)->content > (*a)->next->content)
				sa(a);
			ra (a);
			count++;
		}
	}
}

int main(int argc, char **argv)
{
	int i;
	int *array;
	t_list *stack_a;

	i = 0;
	if (argc < 3)
		return (printf("ERROR"), 1);
	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (1);
	while (i < ((argc - 1)))
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stack_a = create_list(array, argc - 1);
	simple(&stack_a);
	t_list *temp = stack_a;
	while (temp != NULL)
	{
		printf("%d <-> ", temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
	return (free(array), free_list(stack_a), 0);
}
