#include   <stdio.h>
#include   <unistd.h>

void main()
{
	printf("Running ls with execl\n");

	/** 첫번째 인수 : 경로이름
		그 이후의 인수 : 명령 라인 인수들
		(char*) NULL은 인수가 더 이상 없음을 나타냄 **/
	execl("/bin/ls", "ls", (char*) NULL );

	printf("execl failed to run ls\n");
}

