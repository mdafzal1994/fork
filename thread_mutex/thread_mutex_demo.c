
#include<stdio.h>
#include <pthread.h>

/*  avoid RACE condition     done  by using  locking and unlocking   */


pthread_mutex_t  mutex_count;   // create mutex



int count=0;
void *thread_inc(void *arg)
{
   while(1)
   {
	        pthread_mutex_lock(&mutex_count);
  		count++;
   		printf("inc thread %d \n",count);

	        pthread_mutex_unlock(&mutex_count);
   }
}


void *thread_dec(void *arg)
{
 while(1)
 {

	        pthread_mutex_lock (&mutex_count);
	count--;

	printf("dec thread %d \n",count);

	        pthread_mutex_unlock (&mutex_count);
 }
}

 int main()
{
        pthread_t tid_inc;// store id of thread
	pthread_t tid_dec;
      /*initializing mutex    return typ  0 -> suc    -1 -> unscs */
       	pthread_mutex_init (&mutex_count,NULL);     //NULL atrrb means    take mutex as non recursive

        pthread_create(&tid_inc,NULL,thread_inc,NULL);

        pthread_create(&tid_dec,NULL,thread_dec,NULL);
     pthread_join(tid_inc,NULL);

     pthread_join(tid_dec,NULL);
     
     pthread_mutex_destroy (&mutex_count);
   return 0;


}

