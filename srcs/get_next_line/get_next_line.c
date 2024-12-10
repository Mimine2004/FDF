/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:30:36 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/20 09:08:42 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	basin_buffer = NULL;
	return (temp);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			cup_buffer = NULL;
			if (basin_buffer)
				return (free(basin_buffer), basin_buffer = NULL, NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = join_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
		if (!basin_buffer)
			return (free(cup_buffer), NULL);
	}
	return (free (cup_buffer), cup_buffer = NULL, basin_buffer);
}

char	*extract_line(char *basin_buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (basin_buffer[i] == '\n')
		i++;
	line = ft_substr(basin_buffer, 0, i);
	return (line);
}

char	*obtain_remaining(char *basin_buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
		i++;
	if (!basin_buffer[i])
	{
		free(basin_buffer);
		basin_buffer = NULL;
		return (NULL);
	}
	i++;
	if (!basin_buffer[i])
		return (free(basin_buffer), basin_buffer = NULL, NULL);
	temp = ft_calloc(ft_strlen(basin_buffer) - i + 1, sizeof(char));
	if (!temp)
		return (free(basin_buffer), basin_buffer = NULL, NULL);
	j = 0;
	while (basin_buffer[i])
		temp[j++] = basin_buffer[i++];
	return (free(basin_buffer), basin_buffer = NULL, temp);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(basin_buffer), basin_buffer = NULL, NULL);
	if (!basin_buffer)
	{
		basin_buffer = ft_calloc(1, sizeof (char));
		if (!basin_buffer)
			return (free(basin_buffer), basin_buffer = NULL, NULL);
	}
	basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer || !basin_buffer[0])
	{
		if (basin_buffer)
			return (free(basin_buffer), basin_buffer = NULL, NULL);
	}
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}

/* #include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int		fd;
	char	*next_line;
	
	fd = open("get_next_line.text", O_RDONLY);
	while ((next_line = get_next_line(fd)) != NULL)
	{
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
} */