/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:12:45 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/14 09:48:15 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	prepare_stack(t_list **stack, t_list *cheapest_node, char stack_name)
{
	if (stack_name == 'a')
	{
		while (*stack != cheapest_node)
		{
			if (cheapest_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
	}
	else
	{
		while (*stack != cheapest_node)
		{
			if (cheapest_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	push_a_to_b(t_list **a, t_list **b, t_list *cheapest_node)
{
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		while (*b != cheapest_node->target && *a != cheapest_node)
			rr(a, b);
	else if (!cheapest_node->above_median && !cheapest_node->target->above_median)
		while ((*a)->content != cheapest_node->content)
			ra(a);
	else if (cheapest_node->above_median && !cheapest_node->target->above_median)
		while (*b != cheapest_node->target && *a != cheapest_node)
			rrr(a, b);
	set_index(*a);
	set_index(*a);
	prepare_stack(a, cheapest_node, 'a');
	prepare_stack(b, cheapest_node->target, 'b');
}

static void	push_b_to_a(t_list **a, t_list **b)
{
	prepare_stack(a, (*b)->target, 'a');
	pa(a, b);
}

static void	sort_n(t_list **a, t_list **b, int size)
{
	t_list	*cheapest_node;

	if (size-- > 3)
		pb(a, b);
	if (size-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (size-- > 3 && !is_sorted(*a))
	{
		cheapest_node = setup_stack_a(*a, *b);
		push_a_to_b(a, b, cheapest_node);
	}
	sort_3(a);
	while (*b)
	{
		setup_stack_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
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