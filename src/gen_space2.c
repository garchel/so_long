/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:04:02 by pauvicto          #+#    #+#             */
/*   Updated: 2022/10/10 06:29:32 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<fcntl.h>
# include	"so_long.h"


int	count_map2(char *path)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	free(line);
	return (count);
}

int	gen_space2(t_data *data, char *path)
{
	int		i;
	int		fd;
	int		count;

	i = 0;
	count = count_map2(path);
	data->check_map = malloc((count + 1) * sizeof(char *));
	if (!data->check_map)
		return (0);
	fd = open(path, O_RDONLY);
	data->check_map[i] = get_next_line(fd);
	while (data->check_map[i++])
		data->check_map[i] = get_next_line(fd);
	close(fd);
	return (1);
}