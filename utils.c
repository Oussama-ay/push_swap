/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:05:13 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 10:22:11 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	int		sig;

	i = 0;
	if (!nptr)
		return (0);
	sig = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -sig;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	return (sig * result);
}

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_3(t_list **a)
{
	t_list	*max;
	t_list	*i;

	if (*a == NULL)
		return ;
	max = *a;
	i = (*a)->next;
	while (i)
	{
		if (max->content < i->content)
			max = i;
		i = i->next;
	}
	if (max == *a)
		ra (a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

int	stack_size(t_list *head)
{
	int		size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

t_list	*find_max(t_list *lst)
{
	t_list	*max;
	t_list	*i;

	if (!lst)
		return (NULL);
	max = lst;
	i = lst->next;
	while (i)
	{
		if (i->content > max->content)
			max = i;
		i = i->next;
	}
	return (max);
}
