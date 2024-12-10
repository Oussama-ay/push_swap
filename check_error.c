/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:13:28 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 10:53:03 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int has_duplicates(t_list *head) 
{
	t_list	*i;
	t_list	*j;

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

static int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int ft_sign(const char c)
{
	return (c == '+' || c == '-');
}

int is_valid_integer(const char *str, long *val) 
{
	int	i;

	*val = ft_atol(str);
	if (*val == 0 && !ft_isdigit(str[0]))
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_sign(str[i]))
			if (str[i + 1] && ft_sign(str[i + 1]) && !ft_isdigit(str[i + 1]))
				return (0);
		i++;
	}
	if (*val > INT_MAX || *val < INT_MIN)
		return (0);
	return (1);
}
