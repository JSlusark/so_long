/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:06 by jjs               #+#    #+#             */
/*   Updated: 2024/10/25 17:07:01 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	*parse_map(int fd, t_map *map_data)
{
	char	*file_content;
	char	*temp;
	int		i;
	char 	*line;

	file_content = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n' )
		{
			ft_printf("Error: newline found at line %d!\n", i + 1);
			free(map_data);
			free(file_content);
			free(line);
			close(fd);
			exit(1);
		}
		if (file_content == NULL)
			file_content = ft_strdup(line);
		else
		{
			temp = ft_strjoin(file_content, line);
			free(file_content);
			file_content = temp;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (!file_content)
	{
		ft_printf("Error: file is empty!\n");
		free(map_data);
		free(file_content);
		close(fd);
		exit(1);
	}
	return (file_content);
}

static int	has_file_extension(char *file, char *extension)
{
	int	file_len;
	int	ext_len;

	if (!file || !extension)
		return (0);
	file_len = ft_strlen(file) - 1;
	ext_len = ft_strlen(extension) - 1;
	if (ext_len > file_len)
		return (0);
	while (ext_len >= 0)
	{
		if (file[file_len] != extension[ext_len])
			return (0);
		file_len--;
		ext_len--;
	}
	return (1);
}

char	**get_map(char *file, t_map *level)
{
	int		fd;
	char	*file_content;

	fd = open(file, O_RDONLY);
	if (!has_file_extension(file, ".ber") || fd < 0)
	{
		ft_printf("Error: file does not exist or has wrong extension format\n");
		free(level);
		close(fd);
		exit(1);
	}
	file_content = parse_map(fd, level);
	close(fd);
	level->map_array = ft_split(file_content, '\n');
	free(file_content);
	return (level->map_array);
}
