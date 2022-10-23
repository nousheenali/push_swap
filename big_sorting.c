/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:52:22 by nali              #+#    #+#             */
/*   Updated: 2022/02/16 21:38:44 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_minmove_n_push(t_stack **stka, t_stack **stkb, int pn1, int pn2)
{	
	t_stack	*stacka;
	t_stack	*stackb;
	int		l;

	stacka = *stka;
	stackb = *stkb;
	l = find_num_elements(stacka);
	if ((pn1 - 1) < (l - pn2 + 1))
	{
		while (--pn1)
			rotate(&stacka, 'a');
	}
	else
	{
		while (l - pn2 + 1)
		{
			rotate_reverse(&stacka, 'a');
			pn2++;
		}	
	}
	push(&stacka, &stackb, 'b');
	*stka = stacka;
	*stkb = stackb;
}

int	check_if_vals_present(long long l1, long long l2, t_stack **a)
{
	t_stack	*tmp;
	int		l;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	tmp = *a;
	l = find_num_elements(tmp);
	while (i < l)
	{
		if (tmp->num >= l1 && tmp->num < l2)
		{
			flag = 1;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (flag);
}

void	ft_get_val_limits(t_stack **a, t_stack **b, long long l1, long long l2)
{
	t_stack	*tmp;
	t_stack	*sa;
	t_stack	*sb;
	int		pos[2];

	if (check_if_vals_present(l1, l2, a) == 0)
		return ;
	sa = *a;
	sb = *b;
	while (find_num_elements(sa))
	{
		tmp = sa;
		while (!(tmp->num >= l1 && tmp->num < l2))
			tmp = tmp->next;
		pos[0] = ft_find_num_pos(sa, tmp->num);
		tmp = sa->prev;
		while (!(tmp->num >= l1 && tmp->num < l2))
			tmp = tmp->prev;
		pos[1] = ft_find_num_pos(sa, tmp->num);
		ft_minmove_n_push(&sa, &sb, pos[0], pos[1]);
		if (pos[0] >= pos[1])
			break ;
	}
	*a = sa;
	*b = sb;
}

t_stack	*start_sort_hundred(long long *limits, t_stack *stacka, t_stack *stackb)
{
	ft_get_val_limits(&stacka, &stackb, limits[0], limits[1]);
	sort_stackb_pushto_stacka(&stacka, &stackb);
	ft_get_val_limits(&stacka, &stackb, limits[1], limits[2]);
	sort_stackb_pushto_stacka(&stacka, &stackb);
	ft_get_val_limits(&stacka, &stackb, limits[2], limits[3]);
	sort_stackb_pushto_stacka(&stacka, &stackb);
	ft_get_val_limits(&stacka, &stackb, limits[3], limits[4] + 1);
	sort_stackb_pushto_stacka(&stacka, &stackb);
	return (stacka);
}

t_stack	*sort_upto_hundred(t_stack *stacka, t_stack *stackb, int l, int *narr)
{
	long long	limits[5];

	sort_array(narr, l);
	limits[0] = ft_find_min(stacka);
	limits[4] = ft_find_max(stacka);
	limits[2] = find_median_array(narr, l);
	limits[1] = get_median(limits[0], limits[2], narr, l);
	limits[3] = get_median(limits[2], limits[4], narr, l);
	stacka = start_sort_hundred(limits, stacka, stackb);
	return (stacka);
}
