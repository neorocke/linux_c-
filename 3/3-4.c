#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<wait.h>

void main()
{
	pid_t	pid;
	pid_t	child_pid;
	int	status;

	if( (pid= fork())  <  0 ) {
		perror("fork failed");
		exit(1);
	} else if(  pid == 0 ) {
		printf("run child\n");
		sleep(5);
		exit(3);
	} else {
		child_pid = wait( &status );
		printf("child[pid:%d] terminated with code 0x%x\n", child_pid, status );
		exit(3);
	}
}

