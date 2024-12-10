/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:35 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 12:08:48 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

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
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
