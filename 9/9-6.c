#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <signal.h>

#define   SIZE  1024

void  main()
{
	int  shmid;
	void  *shmaddr;
	struct  shmid_ds  shm_stat;

	shmid = shmget( (key_t)234,  SIZE, IPC_CREAT | 0666 );
	shmaddr = shmat( shmid,  (void*)0, 0 );

	printf("data read from shared memory : %s\n", (char*) shmaddr );
	shmdt( shmaddr );
	shmctl( shmid,  IPC_STAT,  &shm_stat );

	kill( shm_stat.shm_cpid, SIGUSR1 );
}

