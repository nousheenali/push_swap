/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:32:07 by nali              #+#    #+#             */
/*   Updated: 2021/12/26 20:32:07 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_num_elements(t_stack *stk)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stk;
	while (tmp->next != stk)
	{
		i++;
		tmp = tmp->next;
	}
	i++;
	return (i);
}

int	ft_find_num_pos(t_stack *stk, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = stk;
	i = 1;
	while (tmp->num != num)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_median_array(int *numarr, int len)
{
	int		i;

	i = len / 2;
	if (len % 2 == 0)
		return ((numarr[i - 1] + numarr[i]) / 2);
	else
		return (numarr[i]);
}

int	find_median_ll(t_stack *stk)
{
	int		len;
	int		j;
	t_stack	*tmp;

	tmp = stk;
	j = 0;
	len = find_num_elements(stk);
	if (len % 2 == 0)
	{
		while (j < (len / 2) - 1)
		{
			tmp = tmp->next;
			j++;
		}
		return ((tmp->num + tmp->next->num) / 2);
	}
	else
	{
		while (j < len / 2 )
		{
			tmp = tmp->next;
			j++;
		}
		return (tmp->num);
	}	
}

void	free_linked_list(t_stack **stk)
{
	t_stack	*head;
	t_stack	*tmp;
	int		i;
	int		l;

	head = *stk;
	i = 0;
	l = find_num_elements(head);
	while (i < l)
	{
		tmp = head;
		head = head->next;
		head->prev = tmp->prev;
		head->prev->next = head;
		free(tmp);
		i++;
	}
	head = NULL;
	*stk = head;
}
