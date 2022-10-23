/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 08:41:03 by nali              #+#    #+#             */
/*   Updated: 2022/02/25 18:10:48 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_input_conditions(int *numarr, int len)
{
	if (len == 1)
		return ;
	if (numarr == NULL)
		ft_putstr_fd("Error\n", 1);
}

int	main(int argc, char **argv)
{
	int		*numarr;
	int		len;
	t_stack	*stacka;
	t_stack	*stackb;

	stackb = NULL;
	stacka = NULL;
	if (argc >= 2)
	{
		numarr = ft_input_args_check(argc, argv, &len);
		if (numarr == NULL || len == 1)
		{
			ft_input_conditions(numarr, len);
			return (1);
		}
		stacka = ft_populate_stack(len, numarr);
		if (ft_check_if_sorted(stacka) != 0)
		{
			ft_free_function(&stacka, numarr);
			return (1);
		}
		stacka = start_sorting(stacka, stackb, len, numarr);
		ft_free_function(&stacka, numarr);
	}	
	return (0);
}
