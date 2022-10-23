/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:42:14 by nali              #+#    #+#             */
/*   Updated: 2021/12/30 12:42:14 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	min_move(int a, int b, int c, int d)
{
	if (a < b)
	{
		if (a <= c && a <= d)
			return ('a');
		else if (c <= a && c <= d)
			return ('c');
		else if (d <= a && d <= c)
			return ('d');
	}
	else
	{
		if (b <= c && b <= d)
			return ('b');
		else if (c <= b && c <= d)
			return ('c');
		else if (d <= b && d <= c)
			return ('d');
	}
	return ('0');
}

t_stack	*ft_bringto_top(t_stack *stackb, char op, int pmax, int pmin)
{
	int	l;

	l = find_num_elements(stackb);
	while ((pmax - 1) && op == 'a')
	{
		rotate(&stackb, 'b');
		pmax--;
	}
	while ((l - pmax + 1) && op == 'b')
	{
		rotate_reverse(&stackb, 'b');
		pmax++;
	}
	while ((pmin - 1) && op == 'c')
	{
		rotate(&stackb, 'b');
		pmin--;
	}
	while ((l - pmin + 1) && op == 'd')
	{
		rotate_reverse(&stackb, 'b');
		pmin++;
	}
	return (stackb);
}

int	ft_perform_min_moves(t_stack **stkb, t_stack **stka, int len, int *r)
{
	char	op;
	int		pmax;
	int		pmin;
	t_stack	*stackb;
	t_stack	*stacka;

	stackb = *stkb;
	stacka = *stka;
	pmax = ft_find_num_pos(stackb, ft_find_max(stackb));
	pmin = ft_find_num_pos(stackb, ft_find_min(stackb));
	op = min_move((pmax - 1), (len - pmax + 1), (pmin - 1), (len - pmin + 1));
	stackb = ft_bringto_top(stackb, op, pmax, pmin);
	push(&stackb, &stacka, 'a');
	if (op == 'c' || op == 'd')
		rotate(&stacka, 'a');
	if (op == 'a' || op == 'b')
		(*r)++;
	*stkb = stackb;
	*stka = stacka;
	return (len - 1);
}
