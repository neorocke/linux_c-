#include  <stdio.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <string.h>

void  main( )
{
	int   fd,   m;
	char   buf[ 30 ] = "Linux  C  Programming";
//	if(  (fd = open( "test", O_WRONLY | O_CREAT,  0644 ) ) == -1 ) { 
//	if(  (fd = open( "test", O_WRONLY | O_CREAT | O_APPEND,  0644 ) ) == -1 ) { 
	if(  (fd = open( "test", O_WRONLY | O_CREAT | O_EXCL,  0644 ) ) == -1 ) { 
		printf("open failed");
		exit( 1 );
	}
	write( fd, buf, strlen(buf) );
	close( fd );
}

