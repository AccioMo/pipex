#include "pipex.h"

int	main(void)
{
	char	*cmds[] = {"lubh", "-l", NULL};

	execve("ls", cmds, NULL);
	perror("huh");
	return (0);
}
