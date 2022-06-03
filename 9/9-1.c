#include <stdio.h>
#include <signal.h>
void  main( )
{
	int   pid,  action,  signumber;
	printf("My  signal  program – Enter PID : ");
	scanf( "%d", &pid );
	printf( "Select Action : (1=STOP) or (2=CONTINUE)?" );
	scanf( "%d", &action );
	if( action == 1 )
		signumber = SIGSTOP;  /** 프로세스 중단 **/
	else
		signumber = SIGCONT; /** 중단된 프로세스가 동작 **/
	kill(  pid,  signumber  );
}

