#include  <stdio.h>
#include  <stdlib.h>
#include  <dirent.h>

void  main( )
{
	DIR  *dp;
	char  name[20];
	printf("Enter  directory  name : ");
	scanf("%s", name );
	if(  (dp = opendir( name ) ) == NULL ) {
		printf("opendir failed");
		exit(1);
	}
	printf("Directory %s exist!\n", name);
	closedir( dp );
}

