/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:54:06 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 12:07:19 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

int main(int ac, char const *av[])
{
	int		i;
	int		j;
	t_list	*a;
	char	**t;
	long	val;

	t = NULL;
	a = NULL;
	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			t = ft_split(av[i], ' ');
			j = 0;
			while (t[j] && is_valid_integer(t[j], &val))
				a = ft_lstadd_back((j++, a), val);
			if (t[j] && !is_valid_integer(t[j], &val))
				return (ft_printf("Error\n"), free_split(t, j), ft_lstclear(&a), 1);
			free_split(t, j);
			i++;
		}
		if (has_duplicates(a))
			return (ft_printf("Error\n"), ft_lstclear(&a), 1);
	}
	ft_printlst(a);
	ft_lstclear(&a);
	return (0);
}
