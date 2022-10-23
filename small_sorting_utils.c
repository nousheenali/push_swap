/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:29:48 by nali              #+#    #+#             */
/*   Updated: 2021/12/27 19:29:48 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_in_upper_half(t_stack **stka, t_stack **stkb, int i)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	while (stackb->num > stacka->num)
	{
		rotate(&stacka, 'a');
		i++;
	}
	push(&stackb, &stacka, 'a');
	while (i)
	{
		rotate_reverse(&stacka, 'a');
		i--;
	}	
	*stka = stacka;
	*stkb = stackb;
}

void	ft_insert_in_lower_half(t_stack **stka, t_stack **stkb, int i)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	while (stackb->num < stacka->prev->num)
	{
		rotate_reverse(&stacka, 'a');
		i++;
	}
	i++;
	push(&stackb, &stacka, 'a');
	while (i)
	{
		rotate(&stacka, 'a');
		i--;
	}
	*stka = stacka;
	*stkb = stackb;
}

void	ft_insert_to_position(t_stack **stka, t_stack **stkb)
{
	int		median;
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	i = 0;
	stacka = *stka;
	stackb = *stkb;
	median = find_median_ll(stacka);
	if (stackb->num < median)
		ft_insert_in_upper_half(&stacka, &stackb, i);
	else
		ft_insert_in_lower_half(&stacka, &stackb, i);
	*stka = stacka;
	*stkb = stackb;
}
