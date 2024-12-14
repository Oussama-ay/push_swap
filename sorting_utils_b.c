/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:40:12 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/14 09:45:47 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	setup_stack_b(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	find_target(a, b);
}
