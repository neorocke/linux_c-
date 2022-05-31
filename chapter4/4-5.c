#include <stdio.h>
#include <unistd.h>

/** 환경 변수 설정  **/
/**char *evnp[] = {"USER=hong", "PATH=/tmp", (char*)NULL }; **/
void main()
{
	char *arg[] = {"ls ",(char*)NULL };
	printf("Running ls with execlp|n");

	
	execp("ls",arg);
	
	printf("execl failed to run ls|n");
}
