/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:06 by jjs               #+#    #+#             */
/*   Updated: 2024/09/19 13:27:32 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	file_content = collect_file_content(fd)
	map_layout = ft_split(map_file,'\n'); // REMEMBER TO FREE THIS AT EVERY OCCASION

}