#include <stdio.h>
#include <unistd.h>

void main()
{
	printf("Running ls with execlp|n");
	
	execlp("ls","ls",(char*)NULL);
	
	printf("execl failed to run ls|n");
}
