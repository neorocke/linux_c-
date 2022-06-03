#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <signal.h>
#include  <unistd.h>

#define	SIZE	1024

int	shmid;

void  signalHandler( int  signo )
{
	shmctl( shmid,  IPC_RMID, 0);
	exit(1);
}


void  main()
{
	void  *shmaddr;

	shmid = shmget( (key_t)234,  SIZE, IPC_CREAT | 0666 ); 
	shmaddr = shmat( shmid,  (void*)0, 0 );
	strcpy( (char*)shmaddr, "Hi. I am GilDong");

	shmdt( shmaddr );

	signal( SIGUSR1, signalHandler );
	pause(); //wait
}

