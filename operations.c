/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:53:27 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 18:49:43 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_list	*swap(t_list *head)
{
	t_list	*i;
	t_list	*tmp;

	if (!head)
		return (NULL);
	i = head;
	if (i->next)
	{
		tmp = i->next;
		i->next = tmp->next;
		tmp->next = head;
		head = tmp;
	}
	return (head);
}

void	push(t_list **head1, t_list **head2)
{
	t_list	*tmp;

	if (head2 && *head2)
	{
		tmp = (*head2)->next;
		(*head2)->next = *head1;
		*head1 = *head2;
		*head2 = tmp;
	}
}

t_list	*rotate(t_list *head)
{
	t_list	*i;

	if (!head)
		return (NULL);
	i = head;
	while (i->next)
		i = i->next;
	i->next = head;
	head = head->next;
	i->next->next = NULL;
	return (head);
}

t_list	*reverse_rotate(t_list *head)
{
	t_list	*i;
	t_list	*tmp;

	if (!head || !head->next)
		return (head);
	i = head;
	while (i->next->next)
		i = i->next;
	tmp = i->next;
	i->next = NULL;
	tmp->next = head;
	head = tmp;
	return (head);
}
