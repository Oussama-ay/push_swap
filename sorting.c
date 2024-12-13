/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:12:45 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/13 14:12:05 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	push_a_to_b(t_list **a, t_list **b, t_list *cheapest_node)


static void	sort_n(t_list **a, t_list **b, int size)
{
	t_list	*cheapest_node;

	if (size-- > 3)
		pb(a, b);
	if (size-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (size-- > 3 && !is_sorted(*a))
	{
		cheapest_node = setup_stacks(*a, *b);
		push_a_to_b(a, b, cheapest_node);
	}
	sort_3(a);
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (!is_sorted(*a))
	{
		if (size == 2)
			sa(a);
		else if (size == 3)
			sort_3(a);
		else
			sort_n(a, b, size);
	}
}
