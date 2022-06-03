#include  <stdio.h>
#include  <unistd.h>
#define    MAX  100

void  main()
{
	char	buffer[MAX];
	int	n;

	alarm( 10 );
	n = read( STDIN_FILENO, buffer, MAX );
	alarm( 0 );
	write( STDOUT_FILENO, buffer, n );
}

