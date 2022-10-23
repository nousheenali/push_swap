/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:32:41 by nali              #+#    #+#             */
/*   Updated: 2021/12/30 17:32:41 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_stack *stk)
{
	t_stack	*tmp;
	int		max;
	int		i;

	tmp = stk;
	max = tmp->num;
	i = 1;
	while (tmp->next != stk)
	{
		i++;
		tmp = tmp->next;
		if (tmp->num > max)
			max = tmp->num;
	}
	return (max);
}

int	ft_find_min(t_stack *stk)
{
	t_stack	*tmp;
	int		min;
	int		i;

	tmp = stk;
	min = tmp->num;
	i = 1;
	while (tmp->next != stk)
	{
		i++;
		tmp = tmp->next;
		if (tmp->num < min)
			min = tmp->num;
	}
	return (min);
}

t_stack	*ft_perform_rotate(t_stack *stacka, int pos)
{
	int	l;
	int	action;

	l = find_num_elements(stacka);
	if (pos <= l / 2)
		action = 0;
	else
		action = 1;
	if (action == 1)
	{
		while (l - pos)
		{
			rotate_reverse(&stacka, 'a');
			pos++;
		}
	}
	else
	{
		while (pos)
		{
			rotate(&stacka, 'a');
			pos--;
		}
	}
	return (stacka);
}

t_stack	*ft_prepare_stacka(t_stack *stacka, int num)
{
	static int	iter;
	t_stack		*tmp;
	int			closest;
	int			pos;

	if (iter == 0)
	{
		iter++;
		return (stacka);
	}
	tmp = stacka;
	while (tmp->next != stacka)
	{
		if (tmp->num < num)
			closest = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num < num)
		closest = tmp->num;
	pos = ft_find_num_pos(stacka, closest);
	stacka = ft_perform_rotate(stacka, pos);
	return (stacka);
}

void	sort_stackb_pushto_stacka(t_stack **stka, t_stack **stkb)
{
	int		len_b;
	int		rotations;
	t_stack	*stackb;
	t_stack	*stacka;

	if (!(*stkb))
		return ;
	stackb = *stkb;
	stacka = *stka;
	rotations = 0;
	stacka = ft_prepare_stacka(stacka, stackb->num);
	len_b = find_num_elements(stackb);
	while (len_b)
		len_b = ft_perform_min_moves(&stackb, &stacka, len_b, &rotations);
	while (rotations)
	{
		rotate(&stacka, 'a');
		rotations--;
	}
	*stkb = stackb;
	*stka = stacka;
}
