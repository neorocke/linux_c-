#include   <stdio.h>
#include   <unistd.h>

void  main()
{
	/** 인수리스트를 내용으로 하는 문자열 배열 **/
	char *arg[] = { "ls", (char*)NULL };
	printf("Running ls with execv\n");

	/** 첫번째 인수 : 경로이름
		두번째 인수 : 인수들의 배열 **/
	execv(  "/bin/ls", arg );

	printf("execv failed to run ls\n");
}

