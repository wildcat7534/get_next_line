/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:06 by cmassol           #+#    #+#             */
/*   Updated: 2024/08/13 11:55:19 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

static char *strSlice;
static char *newstr;
static char *line;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
unsigned long	ft_strlen(const char *s);
char	*ft_strrchr(const char *str, int c);\
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_line(char *str);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif