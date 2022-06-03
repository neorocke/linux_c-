#include  <stdio.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <stdlib.h>
#define   MAX   10

void  main( )
{
	int   fd,   m,  length = 0;
	char   buf[ MAX ];

	if(  (fd = open( "test",  O_RDONLY ) ) == -1 ) {
		exit( 1 );
	}

	while(  ( m = read( fd, buf, MAX ) ) > 0 )
		length += m;

	printf("Total characters in test : %d\n", length );
	close( fd );
}

