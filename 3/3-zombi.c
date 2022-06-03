#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>

void main()
{
	pid_t  pid;

	if(  (pid=fork()) < 0 ) {
		perror("fork failed");
	} else if( pid == 0 ) {
		sleep(10);
		printf("child process(%d) : exit(0)\n", getpid() );
		exit(0);
	} else {
		printf("parent process(%d) : Press any key\n", getpid() );
		getchar();
	}
}

