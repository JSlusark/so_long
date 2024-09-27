/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:06 by jjs               #+#    #+#             */
/*   Updated: 2024/09/27 19:03:42 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*parse_map(int fd)
{
	char	*file_content;
	char	*line;
	char	*temp;
	int		i;

	file_content = NULL;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[i] == '\0' || line[0] == '\n' ) // does not see as error if last line of doc has /n
		{
			printf("Error: empty line found at line %d!\n", i + 1);
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
		i++;
	}
	if (!file_content)
	{
		printf("Error: file is empty!\n");
		free(file_content);
		close(fd);
		exit(1);
	}
	return (file_content);
}

static int	has_file_extension(char *file, char *extension) // doing this in case file ext needs to be diff in future
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

char	**get_map(char *file, t_map *map_data)
{
	int		fd;
	char	**map_array;
	char	*file_content;

	if (!has_file_extension(file, ".ber"))
	{
		printf("Error: use the correct file extension\n");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: file not found!\n");
		exit(1);
	}
	file_content = parse_map(fd);
	// check for documents that have spaces they should be err
	map_array = ft_split(file_content, '\n');
	// collect_sprites(map_array, map_data);
	close(fd);
	free(file_content);
	verify_map(map_array, map_data);
	return(map_array);
}