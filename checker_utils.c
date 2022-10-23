/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:53:43 by nali              #+#    #+#             */
/*   Updated: 2022/02/07 09:01:42 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_valid_instruction(char *buf)
{
	char	*s[12];
	int		i;

	s[0] = "sa";
	s[1] = "sb";
	s[2] = "ss";
	s[3] = "pa";
	s[4] = "pb";
	s[5] = "ra";
	s[6] = "rb";
	s[7] = "rr";
	s[8] = "rra";
	s[9] = "rrb";
	s[10] = "rrr";
	s[11] = NULL;
	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(buf, s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	perform_action_stack_2(t_stack **stka, t_stack **stkb, char *buf)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	if (ft_strcmp(buf, "ra") == 0)
		rotate(&stacka, 'e');
	else if (ft_strcmp(buf, "rb") == 0)
		rotate(&stackb, 'e');
	else if (ft_strcmp(buf, "rr") == 0)
		rotate_r(&stacka, &stackb);
	else if (ft_strcmp(buf, "rra") == 0)
		rotate_reverse(&stacka, 'e');
	else if (ft_strcmp(buf, "rrb") == 0)
		rotate_reverse(&stackb, 'e');
	else if (ft_strcmp(buf, "rrr") == 0)
		rotate_reverse_r(&stacka, &stackb);
	*stka = stacka;
	*stkb = stackb;
}

void	perform_action_stack(t_stack **stka, t_stack **stkb, char *buf)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = *stka;
	stackb = *stkb;
	if (ft_strcmp(buf, "sa") == 0)
		swap(stacka, 'e');
	else if (ft_strcmp(buf, "sb") == 0)
		swap(stackb, 'e');
	else if (ft_strcmp(buf, "ss") == 0)
		swap_s(stacka, stackb);
	else if (ft_strcmp(buf, "pa") == 0)
		push(&stackb, &stacka, 'e');
	else if (ft_strcmp(buf, "pb") == 0)
		push(&stacka, &stackb, 'e');
	else
		perform_action_stack_2(&stacka, &stackb, buf);
	*stka = stacka;
	*stkb = stackb;
}

void	write_to_file(int fd)
{
	int		len;
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		len = ft_strlen(line);
		write(fd, line, len);
		if (ft_strchr(line, '\n') == NULL)
			break ;
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
}

char	*get_instruction(char *buf)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = open("file1.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = buf;
		buf = ft_strjoin(buf, line);
		if (ft_strchr(line, '\n') == NULL)
			break ;
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL && tmp != NULL)
	{
		free(tmp);
		free(line);
	}
	return (buf);
}
