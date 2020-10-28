#include<stdio.h>
 #include <unistd.h>
#include <stdlib.h>
int main()
{
   int pfd[1];
   char rbuffer[127];
   int pipe_return;
   pid_t cpid;
  // pipe_return=pipe(pfd);
   
   cpid=fork();
   if(cpid)
   {
      // parent 
      write(pfd[1],"Cdoo\n",5);
       close(pfd[1]);
 }
 else if(cpid==0)
 {  // child 
    read(pfd[0],rbuffer,128);
    printf("read child : %s\n",rbuffer);
     close(pfd[0]);
 }
return 0;
}



