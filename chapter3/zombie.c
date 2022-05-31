#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

void main()
{
	pid_t pid;

	if((pid=fork()) < 0){
		perror("fork failed");
		exit(1);
	} else if(pid == 0) {
		sleep(10);
		printf("child process:(%d) : exit(0) \n", getpid());
		exit(2);
	} else {
		printf("parent proces(%d) : press any key \n",getpid());
		getchar();
	}
	
}
