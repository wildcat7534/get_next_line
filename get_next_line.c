/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:03 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/12 14:41:08 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int			i;

	while (str[i] != '\n' && str[i])
		i++;
	while (str[i] && str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';

	return (line);
}
char	*get_next_line(int fd)
{
	//static char	*str;
	char		*buffer;
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (!ft_strrchr(str, '\n') && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		write(1, "ret = ", 6);
/*		write(1, buffer, 1);
		write(1, "\n", 1);*/
		
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		tmp = ft_strjoin(str, buffer);
		str = tmp;
		free(tmp);
	}
	free(buffer);
	return (str);
}

