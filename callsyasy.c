#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <stdio.h>


int main()
{

  int d;
  d=open("desd.txt",O_WRONLY);//|O_CREAT);
  if(d==-1)
  {
      perror("file  not found1 \n");
  
  }


}
