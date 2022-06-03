#include  <stdio.h> 
#include  <signal.h>
#include  <unistd.h>
#include  <stdlib.h>
#define  SIZE  4

void  main()
{
	char   *arg[3] = { "abc",  "def",  "ghi" };
	char   buffer[SIZE];
	int    fds[2],  m;

	if(  pipe( fds ) == -1 ) {
		exit(1);
	}

	for( m=0;  m<3;  m++ )
		write(  fds[1],  arg[m],  SIZE );
	for( m=0;  m<3;  m++ ) {
		read(  fds[0],  buffer,  SIZE );
		printf( "%s\n",  buffer );
	}
}

