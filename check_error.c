/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:13:28 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/15 13:35:13 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	has_duplicates(t_list *head)
{
	t_list	*i;
	t_list	*j;

	if (!head)
		return (0);
	i = head;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_sign(const char c)
{
	return (c == '+' || c == '-');
}

int	is_valid_integer(const char *str, long *val)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (ft_sign(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	*val = ft_atol(str);
	if (*val > INT_MAX || *val < INT_MIN)
		return (0);
	return (1);
}
