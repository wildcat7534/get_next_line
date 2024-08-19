/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:06:47 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/13 12:02:13 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	size_t	cursor;
	char	*buffer;
	char	*line;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	strSlice = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	tmp = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (1);
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: cannot open file %s\n", argv[1]);
		return (1);
	}
	cursor = 1;
	while (cursor)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		buffer[cursor] = '\0';
		//ft_strlcpy(str, buffer, BUFFER_SIZE);
		tmp = ft_strjoin(strSlice, buffer);
		//free(str);
		strSlice = ft_strdup(tmp);
		//printf("%s", str);
		line = get_line(strSlice);
		if (line)
			printf("%s", line);
		//printf("%s", line);
	}
	/*	cursor = get_cursor(fd);
		while (cursor)
		{
			printf("%s\n", cursor);
			//free(cursor);
			cursor = get_line(fd);
		}*/
	printf("%s", newstr);
	close(fd);
	return (0);
}