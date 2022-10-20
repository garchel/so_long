/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:58:37 by pauvicto          #+#    #+#             */
/*   Updated: 2022/06/24 19:03:35 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reach_save_line(int fd, char *temp_line)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(temp_line, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		temp_line = ft_strjoin(temp_line, buffer);
	}
	free(buffer);
	return (temp_line);
}

char	*store_line(char *temp_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp_line[i])
		return (NULL);
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (temp_line[i] && temp_line[i] != '\n')
	{
		line[i] = temp_line[i];
		i++;
	}
	if (temp_line[i] == '\n')
	{
		line[i] = temp_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*prep_temp_line(char *temp_line)
{
	int		i;
	int		i2;
	char	*line;

	i = 0;
	i2 = 0;
	while (temp_line[i] && temp_line[i] != '\n')
		i++;
	if (!temp_line[i])
	{
		free(temp_line);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(temp_line) - i + 1));
	if (!line)
		return (NULL);
	i++;
	while (temp_line[i])
		line[i2++] = temp_line[i++];
	line[i2] = '\0';
	free(temp_line);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_line = reach_save_line(fd, temp_line);
	if (!temp_line)
		return (NULL);
	line = store_line(temp_line);
	temp_line = prep_temp_line(temp_line);
	return (line);
}
