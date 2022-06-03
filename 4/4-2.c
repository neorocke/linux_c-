#include   <stdio.h>
#include   <unistd.h>

void main()
{
	printf("Running ls with execlp\n");

	/** 첫번째 인수 : 파일이름
		그 이후의 인수 : 명령 라인 인수들
		(char*) NULL은 인수가 더 이상 없음을 나타냄
		ls프로그램은 PATH환경변수에서 찾음  **/
	execlp( "ls",  "ls",  (char*)NULL );

	printf("execlp failed to run ls\n");
}

