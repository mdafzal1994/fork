#include<stdio.h>
#include<semaphore.h>

#include<pthread.h>

sem_t count_sem;

int count=0;  // shared resouce 
void *thread_inc(void *thread)
	{ while(1)
		{	
		sem_wait(&count_sem);//lock
		printf("enter inc thread\n");
	    	count++;
	    	printf("exit inc  thread\n");
	       sem_post(&count_sem);  //unlock
	}}


void *thread_dec(void *thread)
        {  
		while(1)
		{
		sem_wait(&count_sem);//lock

                printf("enter dec thread\n");
                count--;
                printf("exit dec  thread\n");

	       sem_post(&count_sem);  //unlock
        }}


int main()
	{
		pthread_t tid_inc;
		pthread_t tid_dec;
            pthread_create (&tid_inc,NULL,thread_inc,NULL);
            pthread_create (&tid_dec,NULL,thread_dec,NULL);
	    if(sem_init(&count_sem,0,1)==-1)
	    {
	       printf("error sem not initilize\n");
	        return 0;
	    }
	    pthread_join(tid_inc,NULL);
	    pthread_join(tid_dec,NULL);
          sem_destroy(&count_sem);


          return 0;
	}




