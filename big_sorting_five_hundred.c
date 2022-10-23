/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_five_hundred.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:52:00 by nali              #+#    #+#             */
/*   Updated: 2022/02/16 21:36:19 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_elements(int *numarr, int *arr, int i, int j)
{
	int	k;

	k = 0;
	while (i < j)
	{
		numarr[k] = arr[i];
		k++;
		i++;
	}	
}

int	get_median(long long min, long long max, int *arr, int l)
{
	int	*numarr;
	int	i;
	int	j;
	int	len;
	int	median;

	i = 0;
	while (arr[i] < min && i < l)
		i++;
	j = i;
	while (arr[j] <= max && j < l)
		j++;
	len = j - i;
	numarr = (int *)malloc(len * sizeof(int));
	if (!numarr)
		return (0);
	copy_elements(numarr, arr, i, j);
	median = find_median_array(numarr, len);
	free(numarr);
	return (median);
}

t_stack	*start_sort_fivehundred(long long *limits, t_stack *stka, t_stack *stkb)
{
	ft_get_val_limits(&stka, &stkb, limits[0], limits[1]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[1], limits[2]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[2], limits[3]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[3], limits[4]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[4], limits[5]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[5], limits[6]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[6], limits[7]);
	sort_stackb_pushto_stacka(&stka, &stkb);
	ft_get_val_limits(&stka, &stkb, limits[7], limits[8] + 1);
	sort_stackb_pushto_stacka(&stka, &stkb);
	return (stka);
}

t_stack	*sort_above_hundred(t_stack *stacka, t_stack *stackb, int l, int *arr)
{
	long long	limits[9];

	sort_array(arr, l);
	limits[0] = ft_find_min(stacka);
	limits[8] = ft_find_max(stacka);
	limits[4] = find_median_array(arr, l);
	limits[2] = get_median(limits[0], limits[4], arr, l);
	limits[6] = get_median(limits[4], limits[8], arr, l);
	limits[1] = get_median(limits[0], limits[2], arr, l);
	limits[3] = get_median(limits[2], limits[4], arr, l);
	limits[5] = get_median(limits[4], limits[6], arr, l);
	limits[7] = get_median(limits[6], limits[8], arr, l);
	stacka = start_sort_fivehundred(limits, stacka, stackb);
	return (stacka);
}
