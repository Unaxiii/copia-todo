/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:29:51 by uelizegi          #+#    #+#             */
/*   Updated: 2025/08/08 15:39:33 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save || !*save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_substr(save, 0, i);
	return (line);
}

static char	*clean_save(char *save)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rest = ft_substr(save, i + 1, ft_strlen_gnl(save + i + 1));
	free(save);
	return (rest);
}

static void	*free_all(char *buf, char *save)
{
	free(buf);
	free(save);
	return (NULL);
}

static char	*read_fd(int fd, char *save)
{
	char		*buffer;
	char		*tmp;
	ssize_t		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			tmp = ft_strjoin_gnl(save, buffer);
			free(save);
			save = tmp;
		}
	}
	if (bytes < 0)
		return (free_all(buffer, save));
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
	{
		save[fd] = malloc(1);
		if (!save[fd])
			return (NULL);
		save[fd][0] = '\0';
	}
	save[fd] = read_fd(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = extract_line(save[fd]);
	save[fd] = clean_save(save[fd]);
	return (line);
}

/* int	main(void)
{
	int		fd1 = open("archivo1.txt", O_RDONLY);
	int		fd2 = open("archivo2.txt", O_RDONLY);
	int		fd3 = open("archivo3.txt", O_RDONLY);
	char	*line;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Error abriendo archivos");
		return (1);
	}

	for (int i = 0; i < 3; i++)
	{
		line = get_next_line_bonus(fd1);
		printf("fd1: %s", line);
		free(line);

		line = get_next_line_bonus(fd2);
		printf("fd2: %s", line);
		free(line);

		line = get_next_line_bonus(fd3);
		printf("fd3: %s", line);
		free(line);
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */