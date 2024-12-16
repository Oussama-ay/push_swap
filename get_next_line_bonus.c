/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:19:35 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/16 14:21:14 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*ft_strndup(const char *s, int n)
{
	char	*dest;
	int		i;

	dest = malloc(n + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*get_line(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

static char	*read_and_store(int fd, char **save)
{
	char		*buffer;
	int			nbr_byts;
	char		*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nbr_byts = 1;
	while (!get_line(*save) && nbr_byts > 0)
	{
		nbr_byts = read(fd, buffer, BUFFER_SIZE);
		if (nbr_byts <= 0)
			return (free(buffer), NULL);
		buffer[nbr_byts] = '\0';
		tmp = *save;
		if (*save)
			*save = ft_strjoin(*save, buffer);
		else
			*save = ft_strdup(buffer);
		free(tmp);
	}
	return (free(buffer), get_line(*save));
}

static char	*extract_line(char **save, char *newline)
{
	char	*line;
	char	*tmp;

	if (newline)
	{
		line = ft_strndup(*save, newline - *save + 1);
		tmp = ft_strdup(newline + 1);
		free(*save);
		if (*tmp == '\0')
		{
			free(tmp);
			*save = NULL;
		}
		else
			*save = tmp;
	}
	else
	{
		line = ft_strdup(*save);
		free(*save);
		*save = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = read_and_store(fd, &save);
	line = extract_line(&save, newline);
	return (line);
}
