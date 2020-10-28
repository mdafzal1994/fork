
#include<stdio.h>
#include <pthread.h>

/*       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
*/


void *thread_start(void *arg)
{

printf("print thread\n");



}

 int main()
{
        pthread_t thread;// store id of thread
        pthread_create(&thread,NULL,thread_start,NULL);

     pthread_join(thread,NULL);
   return 0;


}

