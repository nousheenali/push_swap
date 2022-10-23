/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:29:14 by nali              #+#    #+#             */
/*   Updated: 2022/01/01 15:29:14 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *stk1, t_stack *stk2)
{
	int	n;
	int	m;

	n = stk1->num;
	m = stk1->next->num;
	stk1->num = m;
	stk1->next->num = n;
	n = stk2->num;
	m = stk2->next->num;
	stk2->num = m;
	stk2->next->num = n;
}

void	rotate_r(t_stack **stk1, t_stack **stk2)
{
	t_stack	*head;

	head = *stk1;
	head = head->next;
	*stk1 = head;
	head = *stk2;
	head = head->next;
	*stk2 = head;
}

void	rotate_reverse_r(t_stack **stk1, t_stack **stk2)
{
	t_stack	*head;

	head = *stk1;
	head = head->prev;
	*stk1 = head;
	head = *stk2;
	head = head->prev;
	*stk2 = head;
}
