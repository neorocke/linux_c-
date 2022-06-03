#include  <stdio.h>
#include  <signal.h>
#include  <unistd.h>

void  main( ) {
	signal( SIGINT,  SIG_IGN );
	while(1) {
		printf("*");
		fflush(stdout);
		sleep(2);
	}
}

