/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:52:22 by nali              #+#    #+#             */
/*   Updated: 2024/01/09 11:01:55 by nali             ###   ########.fr       */
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

/*
	STEPS:
	1. As a check make sure there are values in the stack between the medians l1 and l2.(for example: l1 is min and l2 is first median)
	2. From top of stack A find a number that lies between l1 and l2. Store its position in pos[0].
	3. From bottom of stack A find a number that lies between l1 and l2. Store its position in pos[1].
	4. Check which number will takes minimun number of moves to reach top of stack A.
	5. If pos[0] is less than pos[1] then rotate the stack A (pos[0] - 1) times. Else reverse rotate the stack A (l - pos[1] + 1) times to bring the number to top of stack A.
	6. Push the number to stack B.
	7. Repeat steps 2 to 6 until there are no numbers between l1 and l2 in stack A.
	8. Now prepare stacka to receive the elements in stack B in sorted order. For the first time when no sorted elements are present in stack A,
	the sorted elements from stack B will be pushed to index 0 of stack A. But from the second time onwards the sorted elements will be placed at the position
	where sorted elements end in stackA. For example: if stackA is 1 2 3 4 5 19 22 17 16 11 and stackB is 6 7 8 9 10 then elements of stack B will be placed at index 5.
	So rotate stackA in revrese to bring sorted elements 1 2 3 4 5 to the bottom so they are undisturbed. then pushe stack B to 
	index 0 and rotatte stack A such that the elements look like this  1 2 3 4 5 6 7 8 9 10 19 22 17 16 11.
	9. Meanwhile in stack B this is how sorting is done. Find the max and min of stack B. Find the position of max and min in stack B. See which one takes min
	number of moves to reach top of stack B. Then push the number to stack A. Repeat this until stack B is empty.
	10. Once first quarter of the numbers are sorted in stack A, repeat steps 1 to 9 for the second quarter of the numbers and so on.

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

/*
	STEPS
	1. sort numbers using bubble sort and store in a new array
	2. find median of the array
	3. find median of the first half of the array
	4. find median of the second half of the array
	5. sort values between min and first median. Then sort values between first median and second median. 
	Then sort values between second median and third median. Then sort values between third median and max.
*/
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
