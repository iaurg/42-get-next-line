/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:44:48 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/11 23:29:38 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*holder = NULL;
	char		*buffer;
	//size_t		nbytes;

	// return the line that has been read
	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(!buffer)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE))
	{
		printf("%s--ENDBUF--", buffer);
	}
	free(buffer);
	if(!holder)
		return (NULL);
	return("hi");
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
	printf("STR: %s \n", get_next_line(file_descriptor));
	return (0);
}
