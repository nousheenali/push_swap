/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:28:02 by nali              #+#    #+#             */
/*   Updated: 2022/02/25 16:08:11 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n_perform_action(t_stack **stka, t_stack **stkb, char *inst)
{		
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	if (check_if_valid_instruction(inst) == 1)
		perform_action_stack(&stacka, &stackb, inst);
	else
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	*stka = stacka;
	*stkb = stackb;
	return (0);
}

void	free_memory(char **inst, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(inst[j]);
		j++;
	}
	free(inst);
}

int	ft_take_instructions(t_stack **stka, t_stack **stkb, char *buf)
{
	char	**inst;
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	buf = get_instruction(buf);
	if (buf != NULL)
	{
		inst = ft_split(buf, 10);
		i = 0;
		while (inst[i])
		{
			if (check_n_perform_action(&stacka, &stackb, inst[i]) == 1)
				return (1);
			i++;
		}	
		free(buf);
		free_memory(inst, i);
	}
	*stka = stacka;
	*stkb = stackb;
	return (0);
}

int	read_input_check_output(t_stack *stacka, t_stack *stackb)
{
	int		fd;
	char	*buf;

	fd = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	write_to_file(fd);
	close(fd);
	buf = (char *)malloc(sizeof(char));
	if (! buf)
		return (1);
	buf[0] = '\0';
	if (ft_take_instructions(&stacka, &stackb, buf) != 0)
		return (1);
	if (ft_check_if_sorted(stacka) != 0 && stackb == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*numarr;
	int		len;
	t_stack	*stacka;
	t_stack	*stackb;

	stackb = NULL;
	if (argc >= 2)
	{
		numarr = ft_input_args_check(argc, argv, &len);
		if (numarr == NULL)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		stacka = ft_populate_stack(len, numarr);
		if (ft_check_if_sorted(stacka) != 0)
			return (1);
		if (read_input_check_output(stacka, stackb) == 1)
			return (1);
		ft_free_function(&stacka, numarr);
	}
	return (0);
}
