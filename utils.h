/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:05:03 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/15 13:44:00 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <limits.h>

/* Linked list */
typedef struct s_list
{
	int				content;
	int				index;
	int				instructions_cost;
	int				above_median;
	struct s_list	*target;
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
int		stack_size(t_list *head);
t_list	*find_max(t_list *lst);
t_list	*find_min(t_list *a);

/* Split */
char	**ft_split(char const *s, char c);
int		free_split(char **result);

/* Check error */
int		has_duplicates(t_list *head);
int		is_valid_integer(const char *str, long *val);

/* Sorting instractions */
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

/* Sorting */
void	ft_sort(t_list **a, t_list **b);
int		is_sorted(t_list *lst);
void	sort_3(t_list **a);
t_list	*setup_stack_a(t_list *a, t_list *b);
void	setup_stack_b(t_list *a, t_list *b);
void	set_index(t_list *lst);

#endif