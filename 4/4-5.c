#include   <stdio.h>
#include   <unistd.h>

void  main()
{
	/** 인수리스트를 내용으로 하는 문자열 배열 **/
	char *arg[] = { "ls", (char*)NULL };
	printf("Running ls with execvp\n");

	/** 첫번째 인수 : 파일이름
		두번째 인수 : 인수들의 배열 **/
	execvp( "ls", arg );

	printf("execvp failed to run ls\n");
}

