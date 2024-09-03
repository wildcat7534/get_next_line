/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:00 by cmassol           #+#    #+#             */
/*   Updated: 2024/09/02 19:48:55 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
char	*ft_strdup(char *str)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	//printf("Malloc ptr ft_strdup\n"); //TODO: remove this line
	if (!ptr)
		return (NULL);
	//ft_bzero(ptr, len + 1);
	ft_strlcpy(ptr, str, len + 1);
	return (ptr);
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		n--;
		ptr[n] = '\0';
	}
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	int		lentotal;

	lentotal = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * lentotal + 1);
	//printf("Malloc new_str ft_strjoin \n"); //TODO: remove this line
	if (!new_str)
		return (NULL);
	//ft_bzero(new_str, lentotal + 1);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
/*	if (start == 1)
	{
	}*/

	free(s1);
	s1 = NULL;
	//printf("Free ft_strjoin s1\n"); //TODO: remove this line
	return (new_str);
}

/*void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	char			*ptr;
	size_t			str_len;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if ((!dst && !src) || (dst == NULL && src == NULL))
		return (dst);
	if (ptr_dst < ptr_src)
	{
		while (n--)
		{
			*ptr_dst++ = *ptr_src++;
		}
	}
	else
	{
		ptr_dst += n;
		ptr_src += n;
		while (n--)
		{
			*--ptr_dst = *--ptr_src;
		}
	}
	return (dst);
}*/
/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst || !src)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		n--;
		ptr_dst[n] = ptr_src[n];
	}
	return (dst);
}*/
/*
 */
