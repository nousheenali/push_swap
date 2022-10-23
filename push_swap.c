/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:33:56 by nali              #+#    #+#             */
/*   Updated: 2022/02/17 12:23:54 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*start_sorting(t_stack *stacka, t_stack *stackb, int len, int *numarr)
{
	if (len == 2)
		sort_two(stacka, 'a');
	else if (len == 3)
		stacka = sort_three(stacka, 'a');
	else if (len == 4)
		stacka = sort_four(stacka, stackb);
	else if (len == 5)
		stacka = sort_five(stacka, stackb);
	else if (len > 5 && len <= 100)
		stacka = sort_upto_hundred(stacka, stackb, len, numarr);
	else
		stacka = sort_above_hundred(stacka, stackb, len, numarr);
	return (stacka);
}

int	ft_check_if_sorted(t_stack *stk)
{
	t_stack	*tmp;

	tmp = stk;
	while (tmp->next != stk)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_free_fn(char **str, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		free(str[i]);
		i++;
	}
	free (str);
}

void	ft_free_function(t_stack **stacka, int *numarr)
{
	if (numarr != NULL)
		free(numarr);
	if (stacka)
		free_linked_list(stacka);
}

int	*ft_input_args_check(int argc, char **argv, int *l)
{
	char		**str;
	int			*numarr;
	static int	len;

	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = handle_input_string(argc, argv);
	len = 0;
	while (str[len])
		len++;
	numarr = ft_check_n_store(str, len);
	ft_free_fn(str, len);
	*l = len;
	if (len == 1)
	{
		free(numarr);
		return (NULL);
	}
	return (numarr);
}
