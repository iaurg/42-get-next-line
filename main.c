#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	/*
	Here, In this code first open() returns 3 because when main process created,
	then fd 0, 1, 2 are already taken by stdin, stdout and stderr.
	*/
	char *temp;
	char *temp2;
	int file_descriptor = open("./41_no_nl", O_RDONLY);
	//printf("file_descriptor: %d \n", file_descriptor);
	temp = get_next_line(file_descriptor);
	temp2 = get_next_line(file_descriptor);
	printf("%s", temp);
	free(temp);
	printf("%s", temp2);
	free(temp2);
	/*
	printf("\n\n");
	printf("%s$", get_next_line(file_descriptor));
	printf("\n\n");
	printf("%s$", get_next_line(file_descriptor));
	printf("\n\n");
	*/
	return (0);
}
