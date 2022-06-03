#include  <stdio.h>
#include  <sys/types.h>
#include  <unistd.h>
#include  <wait.h>

void  main()
{
	pid_t	pid;
	pid_t	child_pid;
	int	status;

	if( (pid= fork())  <  0 )
		perror("fork failed");
	else if(  pid == 0 )  /** child process **/
		execl("/bin/ls", "ls", (char*)NULL );
	else /** parent process **/
		child_pid = wait( &status );
}

