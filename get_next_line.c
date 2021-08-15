/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:44:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/15 11:19:10 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*holder = NULL;
	char		*buffer;
	char		*final_line;
	int			read_fd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0) // Catch errors after all
	{
		free_and_reset(buffer);
		return (NULL);
	}
	if (!holder)
		holder = ft_strdup("");
	read_fd = read_line(&holder, &buffer, &final_line, fd);
	free_and_reset(buffer);
	if (!final_line && read_fd <= 0)
	{
		// 1 leak solved
		free_and_reset(holder);
		return (NULL);
	}
	return(final_line);
}

ssize_t	read_line(char **holder, char **buffer, char **final_line, int fd)
{
	ssize_t		read_result;
	char		*temp_result;

	read_result = 1;
	// read_result < BUFFER_SIZE
	while (!ft_strchr(*holder, '\n') && read_result)
	{
		read_result = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[read_result] = '\0'; // Allow string work
		temp_result = *holder; // Prepare to join
		*holder = ft_strjoin(temp_result, *buffer);
		free(temp_result);
	}
	*final_line = split_line(holder);
	if(read_result == 0 && !*holder)
		return (0);
	/*
	if (!*final_line)
		free_and_reset(*final_line);
	*/
	return (read_result);
}

char	*split_line(char **holder)
{
	int		i;
	char	*temp_holder;
	char	*holder_copy;

	i = 0;
	while ((*holder)[i] != '\0')
	{
		if ((*holder)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	//printf("----%s----\n", *holder);
	if (i == 0 || !*holder)
		return (NULL);
	//printf("****%d****\n", i);
	temp_holder = *holder;
	holder_copy = ft_substr(temp_holder, 0, i);
	*holder = ft_strdup("");
	free (temp_holder);
	temp_holder = NULL;
	return(holder_copy);
}

void	free_and_reset(void *var)
{
	free(var);
	var = NULL;
}
