#include <stdio.h>
#include <unistd.h>

void main()
{
	printf("Running ls with execl|n");
	
	execl("/bin/ls","ls",(char*) NULL);
	
	printf("execl failed to run ls|n");
}
