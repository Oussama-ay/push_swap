/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:35 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 10:22:30 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sa(t_list **a)
{
	*a = swap(*a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	*b = swap(*b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	*a = swap(*a);
	*b = swap(*b);
	ft_printf("ss\n");
}
