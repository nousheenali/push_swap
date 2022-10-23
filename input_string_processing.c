/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_string_processing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:23:24 by nali              #+#    #+#             */
/*   Updated: 2022/02/17 12:23:24 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*str_join(char *s1, const char *s2)
{
	int		l1;
	char	*str;
	int		i;
	int		j;

	l1 = ft_findlen(s1);
	str = (char *)malloc((l1 + ft_findlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (l1 > 0)
	{	
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	**handle_input_string(int argc, char **argv)
{
	int		i;
	char	*s;
	char	**result;

	i = 1;
	while (i < argc)
	{
		s = str_join(s, argv[i]);
		s = str_join(s, " ");
		i++;
	}
	result = ft_split(s, ' ');
	free(s);
	return (result);
}
