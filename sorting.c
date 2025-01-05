/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:12:45 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/05 16:49:54 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	complete_rotation(t_list **stack, t_list *cheapest_node
							, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ra (stack);
			else
				rra (stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				rb (stack);
			else
				rrb (stack);
		}	
	}
}

static void	set_rank(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		rank;

    if (!stack)
        return;
	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (current->content > compare->content)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

static void push_a_to_b(t_list **a, t_list **b)
{
	set_rank(*a);
	int med = stack_size(*a) / 2;
	while ((*a)->rank > med)
		ra(a);
	pb(a, b);
}

static void	push_b_to_a(t_list **a, t_list **b, t_list *cheapest_node)
{
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		while (*a != cheapest_node->target && *b != cheapest_node)
			rr(a, b);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		while (*a != cheapest_node->target && *b != cheapest_node)
			rrr(a, b);
	mark_above_median(*a);
	mark_above_median(*b);
	complete_rotation(b, cheapest_node, 'b');
	complete_rotation(a, cheapest_node->target, 'a');
	pa(a, b);
}

static void	sort_n(t_list **a, t_list **b, int size)
{
	while (!is_sorted(*a) && stack_size(*a) > 3)
		push_a_to_b(a, b);
	if (!is_sorted(*a) && stack_size(*a) == 3)
		sort_3(a);
	while (*b)
		push_b_to_a(a, b, setup_stack_b(*a, *b));
	mark_above_median(*a);
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
