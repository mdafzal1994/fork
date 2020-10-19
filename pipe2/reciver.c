#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//receiver

int main()
{
   int fd;
   char rbuffer[128];
  fd=open("desd",O_RDONLY);
  if(fd==-1)
  {
  
    perror("read file not found\n");
    exit(0);
  
  } 
 
  read(fd,rbuffer,128);
  printf("receive : %s\n",rbuffer);
  close(fd);



return 0;
}

