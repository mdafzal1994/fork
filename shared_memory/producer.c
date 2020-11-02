#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include<stdio.h>
int main()
{
    int a;
    int shm_fd=shm_open("/cdac",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);  // name of file ,create file ,permission
    ftruncate(shm_fd,sizeof(int));
    int *count=(int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);


    while(1)
    {
    
      scanf("%d",&a);
      *count=a;
      sleep(2);
    }

shm_unlink("/cdac");



return 0;
}


