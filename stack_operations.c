/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:27:15 by nali              #+#    #+#             */
/*   Updated: 2021/12/27 11:27:15 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int number, t_stack *head)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = number;
	head = new;
	new->next = head;
	new->prev = head;
	return (head);
}

void	ft_add_node_end(int number, t_stack *head)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->num = number;
	tmp->next = new;
	new->next = head;
	new->prev = tmp;
	head->prev = new;
}

t_stack	*ft_add_node_begin(int number, t_stack *head)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = number;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	head = new;
	return (head);
}

t_stack	*ft_insert_first_inposition(t_stack *stk)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*prev;

	first = stk;
	stk = stk->next;
	tmp = stk;
	prev = tmp;
	while (tmp->next != NULL)
	{
		if (first->num > tmp->num)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		else
		{
			first->next = tmp;
			prev->next = first;
			return (stk);
		}
	}
	tmp->next = first;
	first->next = NULL;
	return (stk);
}

t_stack	*ft_populate_stack(int len, int *narray)
{
	int		i;
	t_stack	*head;

	head = NULL;
	i = 0;
	if (head == NULL)
		head = ft_new_node(narray[i], head);
	i++;
	while (i < len)
	{
		ft_add_node_end(narray[i], head);
		i++;
	}
	return (head);
}
