/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:15:42 by nali              #+#    #+#             */
/*   Updated: 2021/12/27 12:15:42 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk, char ch)
{
	int	n;
	int	m;

	n = stk->num;
	m = stk->next->num;
	stk->num = m;
	stk->next->num = n;
	if (ch != 'e')
	{
		write(1, "s", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack **stk, char ch)
{
	t_stack	*head;

	head = *stk;
	head = head->next;
	*stk = head;
	if (ch != 'e')
	{
		write(1, "r", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
	}
}

void	rotate_reverse(t_stack **stk, char ch)
{
	t_stack	*head;

	head = *stk;
	head = head->prev;
	*stk = head;
	if (ch != 'e')
	{
		write(1, "rr", 2);
		write(1, &ch, 1);
		write(1, "\n", 1);
	}
}

void	delete_node(t_stack **stk)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stk;
	if (head == NULL)
		return ;
	if (head->next == head && head->prev == head)
	{	
		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = head->next;
		head->prev = tmp->prev;
		head->prev->next = head;
		free(tmp);
	}
	*stk = head;
}

void	push(t_stack **from, t_stack **to, char ch)
{
	int		n;
	t_stack	*head_f;
	t_stack	*head_t;

	head_f = *from;
	head_t = *to;
	n = head_f->num;
	delete_node(&head_f);
	if (head_t == NULL)
		head_t = ft_new_node(n, head_t);
	else
		head_t = ft_add_node_begin(n, head_t);
	*from = head_f;
	*to = head_t;
	if (ch != 'e')
	{
		write(1, "p", 1);
		write(1, &ch, 1);
		write(1, "\n", 1);
	}
}
