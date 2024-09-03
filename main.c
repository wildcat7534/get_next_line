/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:06:47 by cmassol           #+#    #+#             */
/*   Updated: 2024/09/02 20:52:14 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out tests/empty.txt

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	printf("argc: %d\n", argc);
	/*	if (argc != 2)
		{
			printf("Usage: %s <file>\n", argv[0]);
			return (1);
		}*/
	fd = open(argv[1], O_RDONLY);
	// fd = open(NULL, O_RDONLY);
	/*	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		{
			printf("Error: cannot open file %s\n", argv[1]);
			return (1);
		}*/
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = NULL;
		// printf("free line Main\n"); //TODO: remove this line
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	printf("free line FINAL Main\n"); // TODO: remove this line
	close(fd);
	return (0);
}