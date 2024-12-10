/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:11:58 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/09 21:45:58 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*_strdup(char	*s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

int	free_split(char **result, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (-1);
}

static int	filling(char const	*s, char **result, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			word = _strdup((char *)s, c);
			if (!word)
				return (free_split(result, i));
			result[i++] = word;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words_nbrs;
	int		i;

	if (!s)
		return (0);
	words_nbrs = count_words((char *)s, c);
	result = (char **)malloc(sizeof(char *) * (words_nbrs + 1));
	if (!result)
		return (0);
	i = filling(s, result, c);
	if (i == -1)
		return (0);
	result[i] = 0;
	return (result);
}
