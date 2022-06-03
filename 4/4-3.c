#include   <stdio.h>
#include   <unistd.h>

/** 환경 변수 설정 **/
char *envp[] = { "USER=hong", "PATH=/tmp", (char*)NULL };

void  main()
{
	printf("Running ls with execle\n");

	/** 첫번째 인수 : 경로이름
		그 이후의 인수 : 명령 라인 인수들
		환경변수를 넘겨줌 **/
	execle(  "/bin/ls",  "ls",  (char*)NULL, envp );

	printf("execle failed to run ls\n");
}

