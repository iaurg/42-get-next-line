/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:22:32 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/14 12:14:24 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	find_c;

	find_c = c;
	while (*s != find_c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	char	*hold_pointer;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_string)
		return (NULL);
	hold_pointer = new_string;
	while (*s1)
		*new_string++ = *s1++;
	while (*s2)
		*new_string++ = *s2++;
	*new_string = '\0';
	return (hold_pointer);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	size_t	counter;

	x = 0;
	if (!dst || !src)
		return (0);
	if (dstsize)
	{
		while (src[x] && x < (dstsize - 1))
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	counter = 0;
	while (src[counter])
		counter++;
	return (counter);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(str) + 1;
	ptr = (char *) malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, size);
	return ((char *) ptr);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned int	counter;
	unsigned char	*memory;

	counter = 0;
	memory = dest;
	while (len > counter)
	{
		memory[counter] = c;
		counter++;
	}
	return (memory);
}

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, '\0', len);
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = malloc(number * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, number * size);
	return (ptr);
}

static	unsigned int	ft_size(size_t str_len, size_t start, size_t max_len)
{
	unsigned int	holder;

	if (start < str_len)
	{
		holder = str_len - start;
	}
	if (start >= str_len)
	{
		holder = 0;
	}
	if (holder > max_len)
	{
		holder = max_len;
	}
	return (holder);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring_ptr;
	unsigned int	new_max_len;
	size_t			str_len;

	if (!s)
		return (NULL);
	str_len = (unsigned int) ft_strlen(s);
	new_max_len = ft_size(str_len, start, len);
	if (new_max_len == 0)
		return (ft_strdup(""));
	substring_ptr = ft_calloc(new_max_len + 1, sizeof(char));
	if (!substring_ptr)
		return (NULL);
	ft_strlcpy (substring_ptr, &s[start], new_max_len + 1);
	return (substring_ptr);
}
