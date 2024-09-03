/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:03 by cmassol           #+#    #+#             */
/*   Updated: 2024/09/02 22:56:47 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_found(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str == NULL)
		return (str = NULL, free(str), NULL);
	if (str[0] == 0)
	{
		free(str);
		str = NULL;
		// printf("Free str line_right FINAL\n"); //TODO: remove this line
		return (NULL);
	}
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	// printf("Malloc line\n"); //TODO: remove this line
	if (!line)
		return (NULL);
	// ft_bzero(line, i + 2);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[++i] = '\0';
	return (line);
}

char	*line_right(char *str)
{
	int		i;
	int		j;
	char	*lineright;

	i = 0;
	if (str[0] == 0)
	{
		// printf("Free str line_right FINAL\n"); //TODO: remove this line
		str = NULL;
		// free(str);
		return (NULL);
	}
	while (str[i] != '\n' && str[i])
		i++;
	lineright = malloc(sizeof(*str) * (ft_strlen(str) - i + 1));
	// printf("Malloc line_right\n"); //TODO: remove this line
	if (!lineright)
		return (NULL);
	// ft_bzero(lineright, ft_strlen(str) - i + 1);
	j = 0;
	while (str[i])
		lineright[j++] = str[++i];
	lineright[j] = '\0';
	free(str);
	// printf("Free str_stash ancienne line_right\n"); //TODO: remove this line
	str = NULL;
	return (lineright);
}

char	*make_stash(int fd, char *str_stash)
{
	char	*buffer;
	int		o_read;
	int		start;

	start = 0;
	// char	*temp;
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	// printf("Malloc buffer\n"); // TODO: remove this line
	if (!buffer)
		return (NULL);
	// ft_bzero(buffer, BUFFER_SIZE + 1);
	o_read = 1;
	while (!ft_strrchr(str_stash, '\n') && o_read != 0)
	{
		o_read = read(fd, buffer, BUFFER_SIZE);
		if (o_read == -1)
			return (free(buffer), buffer = NULL, NULL);
		if (o_read == 0)
		{
			if (start == 0)
			{
				// return (str_stash = NULL, free(str_stash), free(buffer),NULL);
				free(str_stash);
				str_stash = NULL;
				// printf("Free str_stash fINAL O_READ\n");// TODO: remove this line
				break ;
			}
		}
		buffer[o_read] = '\0';
		str_stash = ft_strjoin(str_stash, buffer);
		start = 1;
	}
	free(buffer);
	buffer = NULL;
	// printf("Free buffer\n"); // TODO: remove this line
	return (str_stash);
}
char	*get_next_line(int fd)
{
	// static char *str_stash = "";
	static char *str_stash;
	char *line;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	if (!str_stash)
		str_stash = ft_strdup(temp);
	free(temp);
	temp = NULL;
	// printf("FREE temp\n"); // TODO: remove this line
	// return (str_stash = NULL, free(str_stash), NULL);
	str_stash = make_stash(fd, str_stash);
	line = get_line_found(str_stash);
	if (!line)
		return (NULL);
	temp = line_right(str_stash);
	str_stash = ft_strdup(temp);
	free(temp);
	temp = NULL;
	// printf("FREE temp line_right\n"); // TODO: remove this line
	return (line);
}