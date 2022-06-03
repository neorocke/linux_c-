#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

/*******************************************/
/*                                         */
/*******************************************/
void printFilePermission( mode_t  mod )
{
	printf("%s%s%s", (mod&S_IRUSR)?"r":"-", (mod&S_IWUSR)?"w":"-", (mod&S_IXUSR)?"x":"-" );
	printf("%s%s%s", (mod&S_IRGRP)?"r":"-", (mod&S_IWGRP)?"w":"-", (mod&S_IXGRP)?"x":"-" );
	printf("%s%s%s", (mod&S_IROTH)?"r":"-", (mod&S_IWOTH)?"w":"-", (mod&S_IXOTH)?"x":"-" );
}

/*******************************************/
/* 입력인자가 디렉토리인지 파일인지 확인   */
/*******************************************/
int checkDirectory( char currPath[], char fileName[] )
{
	struct stat st;
	char fullPathName[500];

	if( strlen( currPath ) == 0 )
		sprintf(fullPathName, "%s", fileName );
	else
		sprintf(fullPathName, "%s/%s", currPath, fileName );

	if( stat( fullPathName, &st ) == -1 ) {
		perror("checkDirectory:stat failed");
		exit(4);
	}
	if( S_ISDIR( st.st_mode ) )
		return 1;
	else
		return 0;
}

/*******************************************/
/*                                         */
/*******************************************/
int printFileInfo( char currPath[], char fileName[] )
{
	struct stat st;
	char fullPathName[500];

	if( strlen( currPath ) == 0 )
		sprintf(fullPathName, "%s", fileName );
	else
		sprintf(fullPathName, "%s/%s", currPath, fileName );

	int	DirFlag = 0;
	if( stat( fullPathName, &st ) == -1 ) {
		perror("printFileInfo:stat failed" );
		exit(3);
	}

	/** 파일 종류에 따라서 문자 출력 **/
	if( S_ISREG( st.st_mode ) ) 
		printf("-");
	else if( S_ISDIR( st.st_mode ) ) {
		printf("d");
		DirFlag = 1;
	}
	else
		printf("x");

	/** 파일 접근권 출력 **/
	printFilePermission( st.st_mode );

	/** 파일 크기와 이름 출력 **/
	printf("  %6ld", st.st_size );
	printf("  %s\n", fileName );
	return DirFlag;
}

/*******************************************/
/*                                         */
/*******************************************/
void printDir( char dirName[] )
{
	DIR	*pCurrDir;
	struct  dirent  *pEntry;
	int	numDir;
	char	subDirName[300];

	if( (pCurrDir = opendir(dirName)) == NULL ) {
		perror("opendir failed");
		exit(1);
	}

	numDir = 0;
	printf("Directory Name : %s\n", dirName );
	while( (pEntry = readdir( pCurrDir )) != NULL ) {
		/** "."과 ".." 디렉토리를 제외한 나머지에 대한 파일 정보를 화면에 출력 **/
		if( !strncmp( pEntry->d_name, ".", 1 ) )
			continue;
		if( !strncmp( pEntry->d_name, "..", 2 ) )
			continue;
		if( printFileInfo( dirName, pEntry->d_name ) )
			numDir++;
	}

	printf("\n");

	/** 하위 디렉토리가 더 이상 없는 경우에는 바로 리턴 **/
	if( numDir == 0 ) {
		closedir( pCurrDir );
		return;
	}

	/** 추가적인 하위 디렉토리가 있는 경우 하위 디렉토리에 대한 출력을 요청하는 재귀함수 호출 **/
	rewinddir( pCurrDir );
	// check sub-directory
	while( (pEntry = readdir( pCurrDir )) != NULL ) {
		if( !strncmp( pEntry->d_name, ".", 1 ) )
			continue;
		if( !strncmp( pEntry->d_name, "..", 2 ) )
			continue;
		/** 추가적인 하위 디렉토리가 있는 경우 하위 디렉토리에 대한 출력을 요청하는 재귀함수 호출 **/
		if( checkDirectory( dirName, pEntry->d_name ) ) {
			sprintf( subDirName, "%s/%s", dirName, pEntry->d_name );
			printDir( subDirName  );
			numDir--;
			if( numDir == 0 )
				break;
		}
	}

	closedir( pCurrDir );

}


/*******************************************/
/*                                         */
/*******************************************/
void  main( int argc, char *argv[] )
{
	if( argc > 2 ) {
		printf("myls : Too many argument\n");
		exit(0);
	}

	if( argc == 1 ) {
		/** 아무런 인자를 입력하지 않은 경우 현재의 작업 디렉토리를 출력 **/
		printDir( "." );
	}
	else {
		/** 추가 입력 인자가 있는 경우 디렉토리라면 디렉토리 내용을 출력하는 함수 호출 **/
		if( checkDirectory( "", argv[1] ) )
			printDir( argv[1] );
		else
		/** 추가 입력 인자가 있는 경우 파일이라면 파일 정보를 출력하는 함수 호출 **/
			printFileInfo( "", argv[1] );
	}
}


