/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:40:12 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/05 13:20:39 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	mark_above_median(t_list *lst)
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

t_list	*find_min(t_list *a)
{
	t_list	*min;
	t_list	*i;

	min = a;
	i = a->next;
	while (i)
	{
		if (i->content < min->content)
			min = i;
		i = i->next;
	}
	return (min);
}

static void	find_target(t_list *a, t_list *b)
{
	t_list			*i;
	t_list			*target_node;
	long			target_value;

	while (b)
	{
		target_value = LONG_MAX;
		i = a;
		while (i)
		{
			if (i->content > b->content
				&& i->content < target_value)
			{
				target_value = i->content;
				target_node = i;
			}
			i = i->next;
		}
		if (target_value == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

static t_list	*get_cheapest(t_list *b)
{
	t_list	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->instructions_cost < cheapest->instructions_cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

static t_list *analyze_stack(t_list *a, t_list *b)
{
	int		size_a;
	int		size_b;
	t_list	*stack;
	int		cost_a;
	int		cost_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	stack = b;
	while (b)
	{
		if (b->above_median)
			cost_b = b->index;
		else
			cost_b = size_b - b->index;
		if (b->target->above_median)
			cost_a = b->target->index;
		else
			cost_a = size_a - b->target->index;
		if ((b->above_median && b->target->above_median) || 
			(!b->above_median && !b->target->above_median))
			b->instructions_cost = MAX(cost_a, cost_b);
		else
			b->instructions_cost = cost_a + cost_b;
		b = b->next;
	}
	return (get_cheapest(stack));
}

t_list	*setup_stack_b(t_list *a, t_list *b)
{
	mark_above_median(a);
	mark_above_median(b);
	find_target(a, b);
	return (analyze_stack(a, b));
}
