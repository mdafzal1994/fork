#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//sender

int main()
{
   int fd;
  fd=open("desd",O_WRONLY);
  if(fd==-1)
  {
  
    perror("file not found\n");
    exit(0);
  
  } 
 
  write(fd,"CDAC\n",5);
  close(fd);
  printf("data send\n");


return 0;
}

