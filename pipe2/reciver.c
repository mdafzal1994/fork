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
   char rbuffer;
  fd=open("desd",O_RDONLY);
  if(fd==-1)
  {
  
    perror("read file not found\n");
    exit(0);
  
  } 
 
  //read(fd,rbuffer,128);i
  int sum=0;
  while (read(fd,&rbuffer, 1) > 0)
  {      
         sum+=rbuffer-'0';
 	 //printf("receive : %c\n",rbuffer);
  }
  //printf("sum sended : %d\n",sum);

  close(fd);


//send after adding  number 
fd=open("desd",O_WRONLY);
  if(fd==-1)
  {

    perror("file not found\n");
    exit(0);

  }
   char c[10];
   c[0]=sum+'0';
  write(fd,c,1);
  close(fd);



return 0;
}

