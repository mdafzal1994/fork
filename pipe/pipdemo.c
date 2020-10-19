#include<stdio.h>
 #include <unistd.h>
#include <stdlib.h>
int main()
{
   int pfd[1];
   char rbuffer[127];
   int pipe_return;
   pipe_return=pipe(pfd);

   pid_t cpid;
   if(pipe_return==-1)
   {
      perror("pipe not created\n");
      exit(0);
   
   }
   
   cpid=fork();
   if(cpid)
   {
      // parent 
      write(pfd[1],"CDAC\n",5);
      
      close(pfd[1]);
   
   
   }
 else
 {
    read(pfd[0],rbuffer,128);
    printf("read child : %s\n",rbuffer);
     close(pfd[0]);
 
 }


return 0;

}



