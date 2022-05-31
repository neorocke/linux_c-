#include <stdio.h>
#include <unistd.h>

/** 환경 변수 설정  **/
char *evnp[] = {"USER=hong", "PATH=/tmp", (char*)NULL };
void main()
{
	printf("Running ls with execlp|n");
	
	execle("/bin/ls","ls",(char*)NULL,envp);
	
	printf("execl failed to run ls|n");
}
