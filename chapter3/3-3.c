#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
	pid_t pid;
	if((pid=fork()) < 0){
		perror("fork failed");
		exit(1);
	} else if(pid == 0) {
		printf("child process(pid=%d),(ppid=%d)\n",getpid(), getppid());
		exit(2);
	} else {
		printf("parent process\(pid=%d),(ppid=%d)n",getpid(), getppid());
		exit(3);
	}
	
}
