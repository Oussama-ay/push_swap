/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:39:45 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/13 09:39:54 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	set_index(t_list *lst)
{
	int		i;
	int		median;

	if (!lst)
		return ;
	median = stack_size(lst) / 2;
	i = 0;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->above_median = 1;
		else
			lst->above_median = 0;
		lst = lst->next;
		i++;
	}
}

static void	find_target(t_list *a, t_list *b)
{
	t_list	*i;
	t_list	*target;
	long	target_value;

	while (a)
	{
		target_value = LONG_MIN;
		i = b;
		while (i)
		{
			if (i->content < a->content 
				&& i->content > target_value)
			{
				target = i;
				target_value = i->content;
			}
			i = i->next;
		}
		if (target_value == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static t_list	*get_cheapest(t_list *a)
{
	t_list	*cheapest;

	cheapest = a;
	while (a)
	{
		if (a->instructions_Cost < cheapest->instructions_Cost)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

static t_list	*analyze_stack(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->instructions_Cost = a->index;
		if (!(a->above_median))
			a->instructions_Cost = size_a - a->index;
		if (a->target->above_median)
			a->instructions_Cost += a->target->index;
		else
			a->instructions_Cost += size_b - a->target->index;
		a = a->next;
	}
	return (get_cheapest(a));
}

t_list	*setup_stacks(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	find_target(a, b);
	return (analyze_stack(a, b));
}
