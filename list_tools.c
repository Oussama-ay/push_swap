/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:17:14 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/18 16:13:53 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_list	*ft_nodenew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = content;
	return (new);
}

void	ft_printlst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*save;

	if (!lst)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		free(*lst);
		*lst = save;
	}
}

t_list	*ft_lstadd_back(t_list *lst, int content)
{
	t_list	*node;
	t_list	*last;

	node = ft_nodenew(content);
	if (lst == NULL)
	{
		lst = node;
		return (lst);
	}
	last = lst;
	while (last->next)
		last = last->next;
	last->next = node;
	return (lst);
}
