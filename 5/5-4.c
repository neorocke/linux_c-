#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

void parent(void)
{
	sem_t * sem_id;

	sem_id=sem_open("mysem", O_CREAT, 0600, 0);
	if(sem_id == SEM_FAILED) {
		perror("parent sem_open");
		return;
	}
	printf("Parent : Waiting for child\n");
	if(sem_wait(sem_id) < 0) {
		perror("sem_wait");
	}
	printf("Parent : OK!!\n");
	sem_close( sem_id );
}

void child(void)
{
	sem_t * sem_id;

	sem_id=sem_open("mysem", O_CREAT, 0600, 0);
	if(sem_id == SEM_FAILED) {
		perror("child sem_open");
		return;
	}
	printf("Child : Sleeping\n");
	sleep(5);
	printf("Child : Posting for parent\n");
	if(sem_post(sem_id) < 0) {
		perror("sem_post");
	}
	sem_close( sem_id );
}

void main()
{
	pid_t pid;
	int status;

        if( (pid=fork()) < 0 ) {
                perror("fork failed");
	}
        else if( pid == 0 ) {
		child();
	}
        else {
		parent();
		wait( &status );
	}
}
