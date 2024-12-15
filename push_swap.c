/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:54:06 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/15 13:32:26 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "utils.h"

static void	_input(char **av, t_list **a)
{
	int		i;
	int		j;
	char	**t;
	long	val;

	i = 1;
	while (av[i])
	{
		t = ft_split(av[i], ' ');
		j = 0;
		while (t[j] && is_valid_integer(t[j], &val))
			*a = ft_lstadd_back((j++, *a), val);
		if (t[j])
			exit((print_str("Error\n", 2), free_split(t), ft_lstclear(a), 1));
		free_split(t);
		i++;
	}
	if (has_duplicates(*a))
		exit((print_str("Error\n", 2), ft_lstclear(a), 1));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac >= 1)
		_input(av, &a);
	ft_sort(&a, &b);
	(ft_lstclear(&a), ft_lstclear(&b));
	return (0);
}
