#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void main(){
	DIR *dp;
	char name[20];
	struct dirent *dirp;
	printf("Enter directory name:");
	scanf("%s", name);
	if((dp = opendir(name)) ==NULL){
		printf("opendir failed");
		exit(1);
	}
	printf("\nFirst search : \n");
	while(dirp = readdir(dp)){
		printf("%s", dirp->d_name);

	}
	rewinddir(dp);

	printf("\n\nSecond search : \n");
	while(dirp = readdir(dp)){
		printf("%s", dirp->d_name);

	}
	printf("\n");
}
