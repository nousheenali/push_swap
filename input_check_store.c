/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_store.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:09:04 by nali              #+#    #+#             */
/*   Updated: 2022/02/07 10:49:36 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(int **ptr, int len)
{
	int	i;
	int	j;
	int	*p;

	i = 0;
	p = *ptr;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (p[i] == p[j])
			{
				free(*ptr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_store_num(char *str, int *num)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	if (ft_strcmp(str, "0") == 0)
		*num = 0;
	else if (ft_strcmp(str, "-1") == 0)
		*num = -1;
	else
	{
		i = ft_atoi(str);
		if (l >= 10)
		{
			if (i == 0 || i == -1)
				return (0);
		}
		*num = i;
	}	
	return (1);
}

int	ft_check_if_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_check_n_store(char **str, int len)
{
	static int	i;
	int			*numarray;

	numarray = (int *)malloc(len * sizeof(int));
	while (str[i] && numarray != NULL)
	{
		if ((ft_check_if_num(str[i])) == 1)
		{
			if (ft_store_num(str[i], &numarray[i]) == 0)
			{
				free(numarray);
				return (NULL);
			}
		}
		else
		{
			free(numarray);
			return (NULL);
		}
		i++;
	}	
	if (ft_check_duplicates(&numarray, len) == 0)
		return (NULL);
	return (numarray);
}
