/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:52:52 by jslusark          #+#    #+#             */
/*   Updated: 2024/09/19 13:30:53 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_update_collector(char *collector)
{
	char	*newline;
	char	*new_collector;

	newline = ft_strchr(collector, '\n');
	if (!newline)
	{
		free(collector);
		return (NULL);
	}
	new_collector = ft_strdup(newline + 1);
	free(collector);
	return (new_collector);
}

static char	*ft_get_line(char *collector)
{
	size_t	len;
	char	*line;

	len = 0;
	while (collector[len] && collector[len] != '\n')
		len++;
	if (collector[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(line, collector, len + 1);
	return (line);
}

static char	*ft_addtocollector(int fd, char *buffer, char *collector,
char *temp)
{
	ssize_t	bytes;

	while (!ft_strchr(collector, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(collector);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!collector)
			collector = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(collector, buffer);
			free(collector);
			collector = temp;
		}
	}
	free(buffer);
	return (collector);
}

static char	*ft_read_to_collector(int fd, char *collector)
{
	char		*buffer;
	char		*temp;

	temp = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	collector = ft_addtocollector(fd, buffer, collector, temp);
	return (collector);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*collector;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	collector = ft_read_to_collector(fd, collector);
	if (!collector || !*collector)
	{
		free(collector);
		collector = NULL;
		return (NULL);
	}
	line = ft_get_line(collector);
	collector = ft_update_collector(collector);
	return (line);
}