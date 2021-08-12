/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:44:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/12 10:52:47 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

ssize_t	read_line(char **holder, char **buffer, char **final_line, int fd);

char	*get_next_line(int fd)
{
	static char	*holder = NULL;
	char		*buffer;
	char		*final_line;
	int			read_n;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	read_n = read_line(&holder, &buffer, &final_line, fd);
	if (read_n <= 0)
		return (NULL);
	return(final_line);
}

ssize_t	read_line(char **holder, char **buffer, char **final_line, int fd)
{
	ssize_t		read_result;

	read_result = 1;
	*holder = "";
	while (!ft_strchr(*buffer, '\n') && read_result)
	{
		read_result = read(fd, *buffer, BUFFER_SIZE);
		*holder = ft_strjoin(*holder, *buffer);
	}
	printf("HOLDER:%s\n", *holder);
	if(!final_line)
		return (0);
	return (read_result);
}

#include <fcntl.h>
int	main(void)
{
	/*
	Here, In this code first open() returns 3 because when main process created,
	then fd 0, 1, 2 are already taken by stdin, stdout and stderr.
	*/
	int file_descriptor = open("./test.txt", O_RDONLY);
	//printf("file_descriptor: %d \n", file_descriptor);
	printf("%s", get_next_line(file_descriptor));
	return (0);
}
