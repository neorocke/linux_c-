#include   <stdio.h>
#include   <unistd.h>

/** 환경 변수 설정 **/
char *envp[] = { "USER=hong", "PATH=/tmp", (char*)NULL };

void  main()
{
	/** 인수리스트를 내용으로 하는 문자열 배열 **/
	char *arg[] = { "ls", (char*)NULL };
	printf("Running ls with execve\n");

	/** 첫번째 인수 : 경로이름
		두번째 인수 : 인수들의 배열
		세번째 인수 : 환경변수  **/
	execve(  "/bin/ls", arg, envp );

	printf("execve failed to run ls\n");
}

