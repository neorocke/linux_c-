#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main(){
  // 파일 오픈을 다양 하게 시도 해보는 프로그램 
  int fd, m;
  char buf[30] ="Linux C Programming";
  // 파일을 오픈 
  //if((fd = open("test", O_WRONLY | O_CREAT, 0644)) == -1) {
  // 파일을  오픈 하고 값을 덮붙임
  //if((fd = open("test", O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1) {
  // 파일이 이미 존재 하면 오류를 발생 시킴 
  if((fd = open("test", O_WRONLY | O_CREAT | O_EXCL, 0644)) == -1) {
    printf("open failed");
    exit(1);
  }
  // 버퍼에 있는 값을 그래돌 test 파일에 넣어 준다 
  write(fd, buf, 20);
  close(fd);
}
