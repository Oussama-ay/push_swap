/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:14:01 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 16:45:02 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

static void	execute_command(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		*a = swap(*a);
	else if (!ft_strncmp(line, "sb\n", 3))
		*b = swap(*b);
	else if (!ft_strncmp(line, "ss\n", 3))
		(1) && (*a = swap(*a), *b = swap(*b));
	else if (!ft_strncmp(line, "pa\n", 3))
		push(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(b, a);
	else if (!ft_strncmp(line, "ra\n", 3))
		*a = rotate(*a);
	else if (!ft_strncmp(line, "rb\n", 3))
		*b = rotate(*b);
	else if (!ft_strncmp(line, "rr\n", 3))
		(2) && (*a = rotate(*a), *b = rotate(*b));
	else if (!ft_strncmp(line, "rra\n", 4))
		*a = reverse_rotate(*a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		*b = reverse_rotate(*b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		(3) && (*a = reverse_rotate(*a), *b = reverse_rotate(*b));
	else
		exit((free(line), print_str("Error\n", 2),
				ft_lstclear(a), ft_lstclear(b), 1));
}

static void	checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command (line, a, b);
		free (line);
		line = get_next_line (0);
	}
	free (line);
	if (is_sorted(*a) && !*b)
		print_str ("OK\n", 1);
	else
		print_str ("KO\n", 1);
}

static void	_input(char **av, t_list **a)
{
	int		i;
	int		j;
	char	**t;
	long	val;

	i = 1;
	while (av[i])
	{
		t = ft_split(av[i], ' ');
		if (!valid_string(t))
			exit((print_str("Error\n", 2), free_split(t), ft_lstclear(a), 1));
		j = 0;
		while (t[j] && is_valid_integer(t[j], &val))
			*a = ft_lstadd_back((j++, *a), val);
		if (t[j])
			exit((print_str("Error\n", 2), free_split(t), ft_lstclear(a), 1));
		free_split(t);
		i++;
	}
	if (has_duplicates(*a))
		exit((print_str("Error\n", 2), ft_lstclear(a), 1));
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac >= 1)
		_input(av, &a);
	checker(&a, &b);
	(ft_lstclear(&a), ft_lstclear(&b));
	return (0);
}
