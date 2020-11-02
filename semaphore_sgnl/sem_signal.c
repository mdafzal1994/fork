#include<stdio.h>
#include<pthread.h>

#include <semaphore.h>


int a,b;
int sum;    //default vlaue is zero due to  global  store to .bss
sem_t inputproc;
sem_t outputproc;
void *thread_input(void *arg)
{ while(1)
	{
        sem_wait(&inputproc);   //lock input processs
	 printf("enter 1  input processing \n");
	 scanf("%d%d",&a,&b);
	 printf("exit 1 input procees \n");
        
      
	 sem_post(&outputproc);  //un lock

   }

}
void *thread_output(void *arg)
{
	while(1)
	{
        sem_wait(&outputproc);
         printf("enter 2 out put  processing \n");
         printf("sum : %d\n",a+b);
         printf("exit 2 putput  procees \n");
        
	 sem_post(&inputproc);
	}


}



int main()
{
   pthread_t tid_input;
   pthread_t tid_output;

   /* creating thread */
   pthread_create(&tid_input,NULL,thread_input,NULL);

   pthread_create(&tid_output,NULL,thread_output,NULL);

   /* initilatizing   semaphore */
   sem_init(&inputproc,0,1);

   sem_init(&outputproc,0,0);

   pthread_join(tid_input,NULL);
   pthread_join(tid_output,NULL);


   sem_destroy(&inputproc);
   sem_destroy(&outputproc);






return 0;
}



