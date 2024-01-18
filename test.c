#include "src/pipex.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int e[2];

	pipe(e);
	char *cmd[] = {"/usr/bin", NULL};
	if (access(*cmd, X_OK) < 0)
		perror("cat");
	return (0);
}