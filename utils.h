/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:05:03 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/10 13:56:05 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <limits.h>

/* Linked list */
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

/* Operations */
t_list	*swap(t_list *head);
void	push(t_list **head1, t_list **head2);
t_list	*rotate(t_list *head);
t_list	*reverse_rotate(t_list *head);

/* Utils */
t_list	*ft_nodenew(int content);
t_list	*ft_lstadd_back(t_list *lst, int content);
void	ft_lstclear(t_list **lst);
void	ft_printlst(t_list *lst);
long	ft_atol(const char *nptr);
int		is_sorted(t_list *lst);

/* Split */
char		**ft_split(char const *s, char c);
int		free_split(char **result, int n);

/* Check error */
int		has_duplicates(t_list *head);
int		is_valid_integer(const char *str, long *val);

/* Sorting operations */
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
