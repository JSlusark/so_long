/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:06 by jjs               #+#    #+#             */
/*   Updated: 2024/09/19 18:56:01 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map_layout)
{
	int i;

	i = 0;
	while (map_layout[i])
	{
		free(map_layout[i]);
		i++;
	}
	free(map_layout);
}
static char	*parse_map(int fd) //what if there is nothing? written in the file
{
	char *file_content;
	char *line;
	char *temp;

	file_content = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (file_content == NULL)
		{
			file_content = ft_strdup(line);
			ft_printf("LINE: %s", line);
		}
		else
		{
			ft_printf("LINE: %s", line);
			temp = ft_strjoin(file_content, line);
			free(file_content);
			file_content = temp;
		}
		free(line);
	}
	return(file_content);
}

static int	has_file_extension(char *file, char *extension) // doing this in case file ext needs to be diff in future
{
	int file_len;
	int ext_len;

	if (!file || !extension)
		return 0;
	file_len = ft_strlen(file) - 1;
	ext_len = ft_strlen(extension) - 1;
	if (ext_len > file_len)
		return 0;
	while (ext_len >= 0)
	{
		if (file[file_len] != extension[ext_len])
			return 0;
		file_len--;
		ext_len--;
	}
	return 1;
}

void	check_map(char *map_file)
{
	int fd;
	char **map_layout;
	char *file_content;

	if (!has_file_extension(map_file, ".ber"))
	{
		ft_printf("Error: use the correct file extension\n");
		exit(1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file not found!\n");
		exit(1);
	}
	file_content = parse_map(fd);
	if (!file_content)
	{
		ft_printf("Error: file is empty!\n");
		exit(1);
	}
	map_layout = ft_split(file_content, '\n');
	free(file_content);
	free_map(map_layout);
}
