#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX 10

void main(){
  // 파일의 크기를 읽어들이는 프로그램 
  int fd, m, length = 0;
  char buf[MAX];
  // 파일 오픈 
  if((fd = open("test",O_RDONLY)) == -1){
    exit(1);
  }
  // 파일 읽기 
  while((m = read(fd,buf,MAX)) > 0)
    length += m;
  printf("Total characters in test : %d\n",length);
  // 파일 닫기 
  close(fd);
}
