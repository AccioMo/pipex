#include "src/pipex.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int e[2];

	pipe(e);
	char *cmd[] = {"cat", NULL};
	int f = fork();
	if (f > 0)
	{
		wait(NULL);
		dup2(e[0], 0);
		close(e[1]);
		execve("/bin/", cmd, NULL);
		perror(*cmd);
	}
	else if (f == 0)
	{
		// dup2(e[1], 1);
		// write(1, "hello\n", 6);
		// close(e[0]);
		// close(e[1]);
		// close(1);
		// close(0);
	}
	return (0);
}