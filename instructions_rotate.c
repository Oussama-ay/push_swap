/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:03:02 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 10:22:32 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_list **a)
{
	*a = rotate(*a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	*b = rotate(*b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	*a = rotate(*a);
	*b = rotate(*b);
	ft_printf("rr\n");
}
