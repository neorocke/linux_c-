#include <stdio.h>
#include <unistd.h>
void main( )
{
	while(1) {
		printf("*");
		fflush(stdout);
		sleep(2);
	}
}

