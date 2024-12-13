/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:54:06 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/13 12:03:34 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

int	main(int ac, char const *av[])
{
	int		i;
	int		j;
	t_list	*a;
	t_list	*b;
	char	**t;
	long	val;

	t = NULL;
	a = NULL;
	b = NULL;
	if (ac >= 1)
	{
		i = 1;
		while (av[i])
		{
			t = ft_split(av[i], ' ');
			j = 0;
			while (t[j] && is_valid_integer(t[j], &val))
				a = ft_lstadd_back((j++, a), val);
			if (t[j])
			{
				ft_printf("test\n");
				return (print_str("Error\n", 2), free_split(t)
					, ft_lstclear(&a), 1);
			}
			free_split(t);
			i++;
		}
		if (has_duplicates(a))
			return (print_str("Error\n", 2), ft_lstclear(&a), 1);
	}
	(ft_printf("After sorting:\n"), ft_sort(&a, &b), ft_printlst(a));
	(ft_lstclear(&a), ft_lstclear(&b));
	return (0);
}
