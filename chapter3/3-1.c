#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	pid_t pid;
	if((pid=fork()) < 0)
		perror("fork failed");
		//exit(1);
	else if(pid == 0)
		printf("child process\n");
		//printf("child process(pid=%d),(ppid=%d)\n",getpid(), getppid());
		//exit(2);
	else
		//child_pid = wait(&status);
		printf("parent process\n");
		//printf("child[pid:%d] terminated with code 0x%x\n", child_pid, status);
		//printf("parent process\(pid=%d),(ppid=%d)n",getpid(), getppid());
		//exit(3);
	
}
