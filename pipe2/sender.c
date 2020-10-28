#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>

//sender

int main()
{
   int fd;
/*  fd=open("desd",O_WRONLY);
  if(fd==-1)
  {
  
    perror("file not found\n");
    exit(0);
  
  } 
 */
  int t=2;
  char c[10];
  int n;
  int i=0;
while(t--)
{
	scanf("%d",&n);
	c[i++]=n+'0';
	printf("data enter %c \n",c[i-1]);
}

//fd=open("desd",O_WRONLY);
fd=open("test.txt",O_CREAT);
  if(fd==-1)
  {

    perror("file not found\n");
    exit(0);

  }


  write(fd,c,2);//strlen(n));
  
  printf("data send\n");
  close(fd);
// read from sender 
/*
  char rbuffer;
  fd=open("desd",O_RDONLY);
  if(fd==-1)
  {

    perror("read file not found\n");
    exit(0);

  }

 
 
  while (read(fd,&rbuffer, 1) > 0)
  {
         
         printf("receive sum : %c\n",rbuffer);
  }
  

  close(fd);

*/


return 0;
}

