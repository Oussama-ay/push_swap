/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:04:22 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/14 16:37:33 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"

void	rra(t_list **a)
{
	*a = reverse_rotate(*a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	*b = reverse_rotate(*b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b) 
{
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
	ft_printf("rrr\n");
}
