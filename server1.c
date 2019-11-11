#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define perms 0666
char fname[256];
int main(){
  int readfd,writefd,fd;
  ssize_t n;
  char buff[512];
  
  if(mkfifo(FIFO1,perms)<0){
  	printf("Wrong with fifo1..!!");
  	}
  if(mkfifo(FIFO2,perms)<0){
  	printf("Wrong eith fifo2.!!");
  	}
  printf("Waiting for connection request,,\n");
  readfd = open(FIFO1,O_RDONLY,0);
  writefd = open(FIFO2,O_WRONLY,0);
  read(readfd,fname,255);
  printf("Client has requested %s file",fname);
  if((fd=open(fname,O_RDWR))<0){
  	strcpy(buff,"File does not exist..\n");
  	write(writefd,buff,strlen(buff));
  	}
 else{
 	while((n=read(fd,buff,512))>0){
 		write(writefd,buff,n);
 		}
 		}
 close(readfd);
 unlink(FIFO1);
 close(writefd);
 unlink(FIFO2);
 return 0;
 }
 
 
  		
