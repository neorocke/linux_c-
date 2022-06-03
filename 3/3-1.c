#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>

void main()
{
	pid_t	pid;
	if( (pid=fork()) < 0 )
		perror("fork failed");
	else if( pid == 0 )
		printf("child process\n");
	else
		printf("parent process\n");
}
