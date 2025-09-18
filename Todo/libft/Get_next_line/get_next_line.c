/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:50:25 by uelizegi          #+#    #+#             */
/*   Updated: 2025/08/08 15:39:33 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	save = read_fd(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(save);
	save = clean_save(save);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */

/* int	main(void)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		printf(">> %s", line);
		free(line);
	}
	return (0);
} */