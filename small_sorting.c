/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:13:54 by nali              #+#    #+#             */
/*   Updated: 2021/12/27 12:13:54 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stk, char ch)
{
	if (ft_check_if_sorted(stk) != 1)
		swap(stk, ch);
}

t_stack	*sort_three(t_stack *stk, char ch)
{
	int	top;
	int	mid;
	int	bottom;

	top = stk->num;
	mid = stk->next->num;
	bottom = stk->next->next->num;
	if (top > mid && mid > bottom && bottom < top)
	{
		swap(stk, ch);
		rotate_reverse(&stk, ch);
	}
	else if (top > mid && mid < bottom && bottom > top)
		swap(stk, ch);
	else if (top > mid && mid < bottom && bottom < top)
		rotate(&stk, ch);
	else if (top < mid && mid > bottom && bottom > top)
	{
		swap(stk, ch);
		rotate(&stk, ch);
	}	
	else if (top < mid && mid > bottom && bottom < top)
		rotate_reverse(&stk, ch);
	return (stk);
}

t_stack	*sort_four(t_stack *stacka, t_stack *stackb)
{
	push(&stacka, &stackb, 'b');
	stacka = sort_three(stacka, 'a');
	ft_insert_to_position(&stacka, &stackb);
	return (stacka);
}

t_stack	*sort_five(t_stack *stacka, t_stack *stackb)
{
	push(&stacka, &stackb, 'b');
	push(&stacka, &stackb, 'b');
	stacka = sort_three(stacka, 'a');
	ft_insert_to_position(&stacka, &stackb);
	ft_insert_to_position(&stacka, &stackb);
	return (stacka);
}
